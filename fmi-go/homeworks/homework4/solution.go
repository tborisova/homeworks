package main

import (
	"io/ioutil"
	"net/http"
	"time"
)

type TimeoutError struct {
	Message string
}

func (e *TimeoutError) Error() string {
	return e.Message
}

func checkUrl(callback func(string) bool, url string, c chan<- string) {
	timeout := time.Duration(3 * time.Second)
	client := http.Client{
		Timeout: timeout,
	}

	resp, err := client.Get(url)

	if err != nil {
		c <- ""
		return
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		c <- ""
		return
	}
	if callback(string(body)) {
		c <- url
	} else {
		c <- ""
	}

	return
}

func SeekAndDestroy(callback func(string) bool, chunkedUrlsToCheck <-chan []string, workersCount int) (string, error) {
	if workersCount < 0 || chunkedUrlsToCheck == nil {
		return "", &TimeoutError{Message: "wow such much"}
	}

	resultChan := make(chan string, 20)
	urlChan := make(chan string, 20)
	start_time := time.Now().UTC()
	avaliableWorkers := 0

	for {
		select {
		case urls, ok := <-chunkedUrlsToCheck:
			if ok {
				for _, urll := range urls {
					urlChan <- urll
				}
			} else {
				return "", &TimeoutError{Message: "wow such much"}
			}
		case url := <-urlChan:
			if avaliableWorkers < workersCount {
				avaliableWorkers++
				go checkUrl(callback, url, resultChan)
			}
		case v := <-resultChan:
			avaliableWorkers--
			if v != "" {
				return v, nil
			}
		default:
			timeout := time.Duration(15 * time.Second)
			elapsed_time := time.Now().UTC()
			if elapsed_time.After(start_time.Add(timeout)) {
				return "", &TimeoutError{Message: "wow such much"}
			} else {
				time.Sleep(1 * time.Second)
			}
		}
	}

	return "", nil
}

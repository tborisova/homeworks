package main

import (
	"io/ioutil"
	"net/http"
	"time"
)

func check(callback func(string) bool, url string, c chan<- string) error {
	timeout := time.Duration(3 * time.Second)
	client := http.Client{
		Timeout: timeout,
	}

	resp, err := client.Get(url)

	if err != nil {
		return err
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return err
	}
	if callback(string(body)) {
		c <- url
	}

	return nil
}

type MyTimeoutError struct {
	Message string
}

func (e *MyTimeoutError) Error() string {
	return e.Message
}

func SeekAndDestroy(callback func(string) bool, chunkedUrlsToCheck <-chan []string, workersCount int) (string, error) {
	if workersCount < 0 || chunkedUrlsToCheck == nil {
		return "", &MyTimeoutError{Message: "wow such much"}
	}

	resultChan := make(chan string, 1)
	start_time := time.Now().UTC()
	for {
		select {
		case urls, ok := <-chunkedUrlsToCheck:
			if ok {
				for i := 0; i <= workersCount; i++ {
					go func(c chan<- string) {
						for _, url := range urls {
							check(callback, url, c)
						}
					}(resultChan)
				}
			} else {
				return "", &MyTimeoutError{Message: "wow such much"}
			}
		case v := <-resultChan:
			return v, nil
		default:
			timeout := time.Duration(15 * time.Second)
			elapsed_time := time.Now().UTC()
			if elapsed_time.After(start_time.Add(timeout)) {
				return "", &MyTimeoutError{Message: "wow such much"}
			}
		}
	}
	return "", nil
}

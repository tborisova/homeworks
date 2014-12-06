package main
import (
"fmt"
"strings"
// "time"
"net/http"
"io/ioutil"
  // "sync"
// 
)
  // var wg  sync.WaitGroup

func check(callback func(string) bool, url string, c chan string) (chan<- string, error){
  // for {
    fmt.Println(url)
    resp, err := http.Get(url)
    if err != nil {
      c <- url
      // break
      return c, err
    }
    defer resp.Body.Close()
    body, err := ioutil.ReadAll(resp.Body)
    if err != nil{
      c <- url
      // break
      return c, err
    }
    if callback(string(body)){
      fmt.Println("DSDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD")
      c <- url
      fmt.Println("jaja")
      // wg.Done()
      // break
      return c, nil
    }
  // }
  return c, nil
}

func SeekAndDestroy(callback func(string) bool, chunkedUrlsToCheck <-chan []string, workersCount int) (string, error){
  someChan  := make(chan string, 1)
  // var v string
  for i := 0; i <= workersCount; i++ {
    // wg.Add(1)
    fmt.Println("DDDDDD")
    urls := <- chunkedUrlsToCheck
    go func(c chan string) {
      for _, url := range urls {
      check(callback, url, c)
      fmt.Println("dkdkdkdkdkdkdkdkdk")
      }
    }(someChan)
    fmt.Println("ddd")
  }
  fmt.Println("jkkjkjk")
  
  for{
  select {
      case v := <- someChan:
        fmt.Println("DKDKDKDKK")
        // wg.Done()
        return v, nil
      default:
        fmt.Println("here")
    }}
  return "", nil
}

func main(){
urls := make(chan []string)
go func() {
    // urls <- []string{"http://www.abv.bg", "http://www.dir.bg"}
    // time.Sleep(5 * time.Second)
    urls <- []string{"http://en.wikipedia.org/wiki/Lorem_ipsum"}
}()

callback := func(contents string) bool {
    return strings.Contains(contents, "Lorem ipsum")
}

result, _ := SeekAndDestroy(callback, urls, 1)

fmt.Println(result)
}// Output: http://en.wikipedia.org/wiki/Lorem_ipsum
package main

//import "fmt"

type Broadcaster struct {
  Registered []chan int
  Sender     chan int
}

func NewBroadcaster() *Broadcaster {
    b := new(Broadcaster)
  b.Registered = make([]chan int, 0)
  b.Sender = make(chan int)
  go func() {
    for {
      value := <-b.Sender
      for _, ch := range b.Registered {
        go func(c chan int) {
                    c <- value
                }(ch)
      }
    }
  }()
  return b
}

func (b *Broadcaster) Register() <-chan int {
    ch := make(chan int)
  b.Registered = append(b.Registered, ch)
  return ch
}

func (b *Broadcaster) Send() chan<- int {
  return b.Sender
}

// func main() {
//   b := NewBroadcaster()
//   one := b.Register()
//   two := b.Register()
//     three := b.Register()
//   go func() {
//     b.Send() <- 1
//   }()
//     println(two)
//     fmt.Printf("One just recieved %v, two recieved %v, three received %v\n", <-one, "nothing", <-three)
//   // One just recieved 1, two recieved 1, too!
//}
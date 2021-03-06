package solution

import (
  "encoding/base64"
  "crypto/rand"
  "math/rand"
)

func getRandomString(int length) string {
 rb := make([]byte, length)
 _, _ := rand.Read(rb)
 rs := base64.URLEncoding.EncodeToString(rb)

 return rs
}

const (
    DOES_NOT_EXIST = iota
    ENQUEUED
    IN_PROGRESS
    UNABLE_TO_PRODUCE
    DONE
)

type Order struct {
    Id      string
    Status  int //Състояние, което се обновява от фабриката
    Words   []string // Думи, за които трябва да бъде произведен
             // регулярен израз
    Result  string // Произведеният регулярен израз
    Channel chan *Order // Канал, по който да бъде върната
                // поръчката, когато бъде приключена
}

type Client struct {
    Name    string
    Orders  map[string]*Order // Всички поръчки от този клиент
                  // където ключът е Order.Id
    Channel chan *Order // Канал, по който клиентът
                // получава поръчка в момента,
                // в който тя бъде приключена
}

func NewOrder(words []string, channel chan *Order) *Order {
  &Order{Words: words, Channel: channel, status: DOES_NOT_EXIST, Result: '', Id: getRandomString(32)}
}

type Factory struct {
  materials map[string]uint16
  workers_count uint8
  Workers []Worker
  // orders []Order
  orders chan *Order // поръчките идват в този канал
}

type Worker struct {
  busy bool //should be struct
}

func NewFactory(workers uint8) *Factory{
  w := make(workers, []Worker)
  &Factory{Workers: w}
}

func (f *Factory) Enqueue(order *Order) {
  orders <- order
}

func (f *Factory) StartProducing() {
  for _ := range workes{
    if workers[i].busy == false{
      workers[i].busy = true;
      order := <-orders
      workers.work(order);
    }
  }
}
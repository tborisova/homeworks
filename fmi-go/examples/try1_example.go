package main

import "testing"
import(
        "gopkg.in/mgo.v2"
        "gopkg.in/mgo.v2/bson"
        "github/tborisova/clean_like_gopher"
)

func testTry(){
   l := make(map[string][]string)
  l["only"] = []string{"people"}
  m := clean_like_gopher.NewCleaningGopher("test", "mongo", "truncation", l)

  session, err := mgo.Dial("localhost:12345")
  if err != nil {
          panic(err)
  }
  defer session.Close()

  // Optional. Switch the session to a monotonic behavior.
  session.SetMode(mgo.Monotonic, true)

  c := session.DB("test").C("people")
  err = c.Insert(&Person{"Ale", "+55 53 8116 9639"},
           &Person{"Cla", "+55 53 8402 8510"})
  if err != nil {
          log.Fatal(err)
  }
  
  m := Mongo.new("one", "trwo", "tree")
  fmt.Println(m)
  result := Person{}
  err = c.Find(bson.M{"name": "Ale"}).One(&result)
  if err != nil {
          log.Fatal(err)
  }

  fmt.Println("Phone:", result.Phone)
  m.Clean()
}
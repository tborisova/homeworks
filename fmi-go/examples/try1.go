
package main

import (
"fmt"
)

import "github.com/tborisova/clean_like_gopher"

func main() {
  l := make(map[string][]string)
  l["only"] = []string{"people"}
  m := clean_like_gopher.NewCleaningGopher("test", "mongo", "truncation", l)
  m.Clean()
  fmt.Println(m)
}
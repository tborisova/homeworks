package main

import (
	"reflect"
	"sort"
	"strings"
)

func Map(data []string, mapper func(string) string) []string {

	for index, value := range data {
		data[index] =  mapper(value)
	}

	return data
}

func SliceCount(slice, elt interface{}) int {
	v := reflect.ValueOf(slice)

	counter := 0
	for i := 0; i < v.Len(); i++ {
		if reflect.DeepEqual(v.Index(i).Interface(), elt) {
			counter++
		}
	}
	return counter
}

func getMostCommonWords(text string, wordCountLimit int) []string {
	result := make([]string, 0)

	words := Map(strings.Fields(text), strings.ToLower)
	sort.Strings(words)

	for _, value := range words {
		if SliceCount(words, value) >= wordCountLimit && SliceCount(result, value) == 0 {
			result = append(result, value)
		}
	}

	return result
}

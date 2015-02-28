package main

func Map(data []string, mapper func(string) string) []string {

	result := []string{}

	for _, value := range data {
		result = append(result, mapper(value))
	}

	return result
}

func Filter(data []string, predicate func(string) bool) []string {

	result := []string{}

	for _, value := range data {
		if predicate(value) {
			result = append(result, value)
		}
	}

	return result
}

func Reduce(data []string, combinator func(string, string) string) string {

	if len(data) == 0 {
		return ""
	}

	result := data[0]

	for index := 1; index < len(data); index++ {
		result = combinator(result, data[index])
	}

	return result
}

func Any(data []string, predicate func(string) bool) bool {

	for _, value := range data {
		if predicate(value) {
			return true
		}
	}

	return false
}

func All(data []string, predicate func(string) bool) bool {

	for _, value := range data {
		if !predicate(value) {
			return false
		}
	}

	return true
}

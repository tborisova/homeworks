package main

func mapSum(funcName func(a int) int, number1 int, number2 int) int {
	return funcName(number1) + funcName(number2)
}

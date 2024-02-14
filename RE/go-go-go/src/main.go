package main

import "fmt"

var arrayCheck = [32]int{48, 48, 121, 30, 87, 3, 103, 3, 3, 103, 22, 5, 69, 1, 87, 109, 91, 89, 88, 6, 13, 87, 15, 84, 8, 22, 91, 81, 90, 71, 12, 77}

func hashPassword(password string) bool {
	var hash string
	hash = "fc5e038d38a57032085441e7fe7010b0"
	var index int = 0
	for i := 0; i < len(password); i++ {
		if password[i] == (hash[index] ^ byte(arrayCheck[index])) {
			index++
		}
	}
	if index == 32 {
		return true
	}
	return false
}

func main() {
	var password string
	fmt.Println("Hello, welcome to GoWorld!")

	fmt.Println("Please enter your password")
	fmt.Scanln(&password)

	if hashPassword(password) {
		fmt.Println("Welcome to GoWorld!")
	} else {
		fmt.Println("Invalid password")
	}
}

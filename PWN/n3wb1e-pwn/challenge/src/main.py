def question_1():
    check = True
    answer = "i386-32-little"
    while check:
        print("1) What architecture system is the program built on? (Ex: arm64-64-little)")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            # Clear console
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
            
        else:
            print("[-] Incorrect! Try again.\n")

            
            
def question_2():
    check = True
    answer = "no canary found"
    while check:
        print("2) Status of Canary Stack?")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
        else:
            print("[-] Incorrect! Try again.\n")

            
def question_3():
    check = True
    answer = "no pie"
    while check:
        print("3) Status of PIE (Position Independent Executable)?")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
            
        else:
            print("[-] Incorrect! Try again.\n")

            
def question_4():
    check = True
    answer = "0x08049200"
    while check:
        print("4) What is the address of the main function? (Ex: 0x080484b6)")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
        else:
            print("[-] Incorrect! Try again.\n")

            
def question_5():
    check = True
    answer = "45"
    while check:
        print("5) How many characters must be entered to overflow the buffer and overwrite the return address? (Example: 100)")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
        else:
            print("[-] Incorrect! Try again.\n")

            
def question_6():
    check = True
    answer = "0x08049186"
    while check:
        print("6) What is the address of the win function? (Ex: 0x080484b6)")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
        else:
            print("[-] Incorrect! Try again.\n")

                    
def question_7():
    check = True
    answer = "'a' * 44 + '\\x86\\x91\\x04\\x08'"
    while check:
        print("7) What is the payload to overwrite the return address with the address of the win function in python2? (Ex: 'A' * 16 + '\\xef\\xbe\\xad\\xde')")
        user_input = input("Answer > ")
        if user_input.lower() == answer:
            print("\033[H\033[J")
            print("[+] Correct!")
            check = False
        else:
            print("[-] Incorrect! Try again.\n")

def main():
    print("\033[H\033[J")
    print("\nWelcome to the n3wb1e-pwn challenge!\n")
    print("You will be asked a series of questions to test your knowledge on binary exploitation and get the flag. Good luck!\n\n")
    question_1()
    question_2()
    question_3()
    question_4()
    question_5()
    question_6()
    question_7()
    print("Congratulations! You have completed the challenge.")
    print("Flag: " + open("flag.txt").read())
    
if __name__ == "__main__":
    main()
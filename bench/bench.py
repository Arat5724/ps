# push_swap benchmark
# written by HyunJun KIM (hyunjuki@student.42seoul.kr)
# tested on M1 pro Mac OSX 13.1
# need Python >=3.6 and matplotlib (pip3 install matplotlib)
# [your push_swap repo]
# | - push_swap
# | - checker_Mac (not mandatory)
# | - push_swap_benchmark.py
# than, $>make re; python3 push_swap_benchmark.py 
import os
import random
import time
import matplotlib.pyplot as plt


class bColors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


INT_MAX = 2147483647
INT_MIN = -2147483648
USER = os.environ.get('USER', 'anonymous')
IS_EXECUTABLE = os.path.isfile('./push_swap')
BIN_FILE = './push_swap' if IS_EXECUTABLE else ''
IS_CHECKER = os.path.isfile('./checker_Mac')
CHECKER = './checker_Mac' if IS_CHECKER else ''


def mandatory():
    cases = [
        ["1. No Arguments", ""],
        ["2. Invalid Arguments", "0 one 2 3"],
        ["3. Duplicated Arguments", "3 2 1 1 2 3"],
        ["4. Arguments over INT_MAX", "3 2 1 2147483649"],
        ["5. Arguments under INT_MIN", "3 2 1 -2147483649"],
        ["6. Only one Argument", "1"],
        ["7. Sorted Argument", "1 2 3 4 5"],
        ["8. 3 Valid Arguments", ""],
        ["9. 5 Valid Arguments", ""],
        ["10. 100 Valid Arguments", ""],
        ["11. 500 Valid Arguments", ""],
    ]

    def do_tests(case: int, cases=None):
        print(f"{bColors.HEADER}{bColors.BOLD}{cases[case - 1][0]} : ", end='')
        args = ' ' + cases[case - 1][1]
        if case == 8:
            lst = list(map(str, random.sample(range(INT_MIN, INT_MAX), 3)))
            args = ' ' + ' '.join(lst)
        if case == 9:
            lst = list(map(str, random.sample(range(INT_MIN, INT_MAX), 5)))
            args = ' ' + ' '.join(lst)
        if case == 10:
            lst = list(map(str, random.sample(range(INT_MIN, INT_MAX), 100)))
            args = ' ' + ' '.join(lst)
        elif case == 11:
            lst = list(map(str, random.sample(range(INT_MIN, INT_MAX), 500)))
            args = ' ' + ' '.join(lst)
        if case > 7:
            os.system(BIN_FILE + args + " | wc -l 1> stdout.pylog 2> stderr.pylog")
            if IS_CHECKER:
                os.system(BIN_FILE + args + " | " + CHECKER + args + " 1> checkerout.pylog 2> checkererr.pylog")
        else:
            os.system(BIN_FILE + args + " 1> stdout.pylog 2> stderr.pylog")

    def clear_files():
        os.system('rm -f *.pylog')
        time.sleep(0.5)

    def check_stdout():
        with open('./stdout.pylog') as f:
            r = f.readlines()
            if len(r) == 0:
                print(f"{bColors.OKGREEN}OK")
            else:
                print(f"{bColors.WARNING}KO")

    def check_stderr():
        with open('./stdout.pylog') as f:
            r = f.readlines()
            if r != []:
                print(f"{bColors.WARNING}STDOUT DETECTED", end=' ')
            with open('./stderr.pylog') as ff:
                rr = ff.readlines()
                if rr == ['Error\n']:
                    print(f"{bColors.OKGREEN}OK")
                else:
                    print(f"{bColors.WARNING}KO")

    def check_stdout_wc():
        with open('./stdout.pylog') as f:
            r = f.readlines()
            r[0].lstrip()
            print(f"{bColors.OKCYAN}{int(r[0])} Instructions", end=' ')
        if IS_CHECKER:
            with open('./checkerout.pylog') as ff:
                rr = ff.readlines()
                rr[0].lstrip()
                print(f"{bColors.OKBLUE}Checker : {rr[0]}", end ='')


    os.system('clear')
    print(f"{bColors.HEADER}Checking your push_swap requires Mandatory Part...")

    for i in range(1, 12):
        do_tests(i, cases)
        if 2 <= i <= 5:
            check_stderr()
        elif i >= 8:
            check_stdout_wc()
        else:
            check_stdout()
        while os.path.isfile('./stdout.pylog') or os.path.isfile('./stderr.pylog') or os.path.isfile('./checkerout.pylog'):
            clear_files()


def benchmark():
    os.system('clear')
    print(f"{bColors.WARNING}WARNING : THIS SEGMENT DOES NOT DETECT 'ERROR' and 'UNSORTED'")
    print()
    print(f"{bColors.BOLD}{bColors.HEADER}How many attempts do you want?")
    attempts = int(input())
    print(f"{bColors.BOLD}{bColors.HEADER}How many arguments do you want?")
    print(f"{bColors.OKCYAN}HINTS : 100 or 500 arguments can test Mandatory Part")
    argument_counts = int(input())
    print(f"{bColors.BOLD}{bColors.HEADER}How about threshold?")
    print(f"{bColors.OKCYAN}HINTS : I'll calculate percentage of 'larger than threshold'")
    threshold = int(input())
    data = []
    for i in range(attempts):
        args = list(map(str, random.sample(range(INT_MIN, INT_MAX), argument_counts)))
        os.system('ARG="' + ' '.join(args) + '";' + BIN_FILE + ' $ARG | wc -l >> dataset.log')
        os.system('clear')
        print(f'{bColors.HEADER}I know you are bored. please {bColors.OKGREEN}BE patient')
        print(f'{bColors.OKCYAN}NOW : {i + 1}')
    with open('./dataset.log') as f:
        print("Reading Results...")
        temp = f.readlines()
        for s in temp:
            if s == '':
                break
            s.lstrip()
            data.append(int(s))

    plt.title(f"{USER}'s push_swap,     {argument_counts}args       {attempts}attempts")
    plt.hist(data, bins=100)
    plt.xlabel('instructions')
    plt.ylabel('appearances')
    plt.grid(True)
    data.sort()
    temp = [(num > threshold) for num in data]
    print()
    print(f"Average : {sum(data) / attempts}")
    print(f"Top 1% : {sum(data[-(attempts // 100):]) / (attempts // 100)}")
    print(f"Low 1% : {sum(data[:(attempts // 100)]) / (attempts // 100)}")
    print(f"Best : {data[0]}")
    print(f"Worst : {data[-1]}")
    print(f"Larger than Threshold : {sum(temp)}, {(sum(temp) / attempts) * 100}%")
    print(f"{bColors.HEADER}If you need, capture the graph")
    print()
    os.system('rm -f dataset.log')
    plt.show()


def main():
    if not IS_EXECUTABLE:
        print("Cannot find push_swap binary executable file!!")
        exit(-1)
    print(f"{bColors.HEADER}1. Check Mandatory")
    print("2. Benchmark your push_swap")
    menu = int(input(f"{bColors.BOLD}Select what do you want : "))
    if menu == 1:
        mandatory()
    elif menu == 2:
        benchmark()
    print(f"{bColors.OKGREEN}Process ends. Thank you!")


if __name__ == '__main__':
    main()

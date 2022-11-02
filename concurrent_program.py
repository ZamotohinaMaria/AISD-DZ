import concurrent.futures
import sys

def quadro(average: float, x: float):
    """функция, считающая квадратичное отклонение, ее работа как раз разбита на потоки

    Args:
        average (float): среднее значение
        x (float): число, для которого считается отклонение
    Returns:
        _type_: квадратичное отклонение
    """
    print((average - x)**2)
    return (average - x)**2

def main():
    """основная функция программы, назначение параметров указано в комментариях
    """
    if len(sys.argv) == 1:
        print('нет параметров')
    
    result_dispersion = 0 # результирующая выборочная дисперсия 
    average = 0 # среднее арифметическое введенных чисел. необходимое для расчетов
    
    for i in range(1, len(sys.argv)):
        average += int(sys.argv[i])
    average /= 3
    with concurrent.futures.ProcessPoolExecutor() as executor:
        result_dispersion += executor.submit(quadro, average, [int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])]).done()
    
    result_dispersion /= 2
    print(result_dispersion)

if __name__ == '__main__':
    main()

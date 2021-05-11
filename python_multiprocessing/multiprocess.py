from multiprocessing import Process, Value, Array
'''
sum = 0
    for i in range(0, id):
        sum += i
    return sum
'''

def run(id):
    sum = 0
    for i in range(0, id):
        sum += i
    print('process ' + str(id) + ' summed ' + str(sum))
    return sum

def generate_processes(count, run_fx, arguments):
    processes = []
    for i in range(0, count):
        processes.append(Process(target=run_fx, args=(arguments[i],)))
    return processes

def start_processes(processes):
    for process in processes:
        process.start()

def join_processes(processes):
    for process in processes:
        process.join()

if __name__ == '__main__':
    n = 10
    args = []
    for i in range(0, n):
        args.append(i)
    processes = generate_processes(n, run, args)
    start_processes(processes)
    join_processes(processes)

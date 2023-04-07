from threading import *
import time

sem = Semaphore(3)

def task(name):
    sem.acquire()

    end = 8 if (name == 'Thread-2') else 5

    for i in range(end):
        print("{} working".format(name))
        time.sleep(1)
    
    sem.release()

if __name__ == "__main__":
    t1 = Thread(target=task, args=('Thread-1',))
    t2 = Thread(target=task, args=('Thread-2',))
    t3 = Thread(target=task, args=('Thread-3',))
    t4 = Thread(target=task, args=('Thread-4',))
    t5 = Thread(target=task, args=('Thread-5',))

    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()
    t5.join()

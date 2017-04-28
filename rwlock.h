//#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

class RWLock{
private:
#ifdef RWLOCK
  pthread_rwlock_t rwlock ;
#else 
        pthread_mutex_t m_mutex=PTHREAD_MUTEX_INITIALIZER; 
#endif
 
public:
    	RWLock();
    	~RWLock();
	
#ifdef RWLOCK
	pthread_rwlock_t* getrwlock();
#else
	// Getter for mutex lock
	pthread_mutex_t* getm_mutex();
#endif

    //Reader
    	void startRead();
    	void doneRead();
    // Writer
    	void startWrite();
    	void  doneWrite();
};


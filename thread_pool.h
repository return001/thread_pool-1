#ifndef __THREAD_POOL_H_H
#define __THREAD_POOL_H_H


typedef void *(*process_func) (void *arg);

/*
*�̳߳����������к͵ȴ���������һ��CThread_worker
*�������������������������һ������ṹ
*/
typedef struct worker
{
    /*�ص���������������ʱ����ô˺�����ע��Ҳ��������������ʽ*/
    process_func process;
    void *arg;/*�ص������Ĳ���*/
    struct worker *next;
} CThread_worker;

/*�̳߳ؽṹ*/
typedef struct
{
    pthread_mutex_t queue_lock;
    pthread_cond_t queue_ready;
    /*����ṹ���̳߳������еȴ�����*/
    CThread_worker *queue_head;
    /*�Ƿ������̳߳�*/
    int shutdown;
    pthread_t *threadid;
    /*�̳߳�������Ļ�߳���Ŀ*/
    int max_thread_num;
    /*��ǰ�ȴ����е�������Ŀ*/
    int cur_queue_size;
} CThread_pool;

extern void pool_init (int max_thread_num);
extern void *thread_routine (void *arg);
extern int 	pool_add_worker (process_func process, void *arg);
extern int 	pool_destroy (void);
#endif

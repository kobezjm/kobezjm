#include<Pthread_copy.h>

typedef struct
{
	const char * sfile;
	const char * dfile;
	int blocksize;
    int flag;
}p_file;

void * jobs(void * arg)
{
        int pos;
        p_file * pt=arg;
        pos=(pt->flag)*(pt->blocksize);
        char str_blocksize[50];
        char str_pos[50];
        bzero(str_blocksize,sizeof(str_blocksize));
        bzero(str_pos,sizeof(str_pos));
        sprintf(str_blocksize,"%d",pt->blocksize);
        sprintf(str_pos,"%d",pos);
        printf("Copy Child Pthread Pid %ld Copy_Pos %d Copy_size %d\n",pthread_self(),pos,pt->blocksize);
        //通过重载方式使用copy功能
        //./copy sfile dfile blocksize pos
        execl("/home/hxf/colinSoft/20210913/Thread/pthread_copy/moudle/COPY","COPY",pt->sfile,pt->dfile,str_blocksize,str_pos,NULL);//重载后被覆盖
}

int Pthread_create(const char * sfile,const char * dfile,int blocksize,int pronum)
{
    int i=0;
    pthread_t tid[pronum];
    p_file * p=NULL;
    p->sfile=sfile;
    p->dfile=dfile;
    p->blocksize=blocksize;
    p->flag=i;
    for(i;i<pronum;i++)
    {
        pthread_detach(tid[i]);
        p->flag=i;
        pthread_create(&tid[i],NULL,jobs,(void *)&p);
    }
    return 0;
}

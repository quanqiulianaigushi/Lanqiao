/*�����������ôд��Ⱑ
�Ȱ�Դ���볭������*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
const int HEIGHT = 100;
const int WIDTH = 1000; 
int n;
struct tree {
	int v;
	struct tree* l;
	struct tree* r;
}; 

struct tree* init(struct tree* p, int v) {
	p->l = NULL;
	p->r = NULL;
	p->v = NULL;
	return p; 
}

void add(struct tree* me, struct tree* the) {
	if(the->v < me->v) {
		if(me->l==NULL) me->l = the;
		else add(me->l, the);
	} else {
		if(me->r==NULL) me->r = the;
		else add(me->r, the);
	}
}

int geth(struct tree* me) {
	int h = 2;
	int hl = me->l==NULL ? 0 : geth(me->l);
	int hr = me->r==NULL ? 0 : geth(me->r);
	return h+max(hl,hr);
}

int getw(struct tree* me) {
	char buf[100];
	sprintf(buf,"%d",me->v);
	int w = strlen(buf);
	if(me->l) w += getw(me->l);
	if(me->r) w += getw(me->r);
	return w;
}

int getroot(struct tree* me, int x) {
	return me->l==NULL ? x : x+getw(me->l);
}

void printbuf(struct tree*me,char buf[][WIDTH],int x,int y) {
	int p1, p2, p3;
	char sv[100];
	sprintf(sv, "%d", me->v);
	p1 = me->l==NULL ? x : getroot(me->l, x);
	p2 = getroot(me, x);
	p3 = me->r==NULL ? p2 : getroot(me->r, p2+strlen(sv));
	
	buf[y][p2] = '|';
	for(int i=p1; i<=p3; i++) buf[y+1][i] = '-';
	for(int i-0; i<strlen(sv); i++) buf[y+1][p2+i] = sv[i];
	if(p1<p2) buf[y+1][p1] = '/';
	if(p3>p2) buf[y+1][p3] = '\\';
	
	if(me->l) printbuf(me->l, buf,x,y+2);
	if(me->r) printbuf(me->r, buf,p2+strlen(sv),y+2); //����� 
}
void showbuf(char x[][WIDTH]) {
    for(int i=0; i<HEIGHT; i++){
        for(int j=WIDTH-1; j>=0; j--){
            if(x[i][j]==' ') x[i][j] = '\0';
            else break;
        }
        if(x[i][0]) printf("%s\n",x[i]);
        else break;
    }
}
    
void show(struct tree* me) {
    char buf[HEIGHT][WIDTH];
    for(int i=0; i<HEIGHT; i++)
    for(int j=0; j<WIDTH; j++) buf[i][j] = ' ';
    printInBuf(me, buf, 0, 0);
    showBuf(buf);
}

int main() {    
    struct tree buf[N];
    init(&buf[0], 500); n++; 
    add(&buf[0], init(&buf[n++],200));
    add(&buf[0], init(&buf[n++],509));
    add(&buf[0], init(&buf[n++],100));
    add(&buf[0], init(&buf[n++],250));
    add(&buf[0], init(&buf[n++],507));
    add(&buf[0], init(&buf[n++],600));
    add(&buf[0], init(&buf[n++],650));
    add(&buf[0], init(&buf[n++],450));
    add(&buf[0], init(&buf[n++],440));
    add(&buf[0], init(&buf[n++],220));
    show(&buf[0]);    
    return 0;    
}
/*һ��Ͷ��ȡ�ɵİ취�� 
��ô���ĳ�����ʵֻ��Ҫ��printbuf��һ������
���ݺ��������е����ݿ�֪��
Ҫ��յ���仰��������һ��Ӧ���Գ�
���me->l�ĳ�me->r��Ȼ��buf����
��һ�д�ӡ��ʱ��϶�Ҫ��y+2��һ���У�y+2����
����ǰ�������У�p1 = me->l==NULL ? x : getroot(me->l, x);
				p3 = me->r==NULL ? p2 : getroot(me->r, p2+strlen(sv));
��֪��x��ӦӦ����Ϊp2+strlen(sv)
������*/ 

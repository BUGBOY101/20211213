#define	_CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#define hashsize 10//��ϣ����
#define NULLKEY -32768
typedef int elemtype;
typedef struct {
	elemtype* elem;//hash����
	int count;//��ǰ��ϣ����Ԫ�ظ���
}hashtable;
int m;
void inithash(hashtable& H) {
	m = hashsize;
	H.count = m;
	H.elem = (int*)malloc(H.count * sizeof(int));
	if (!H.elem)
		return;
	else
	{
		for (int i = 0; i < H.count; i++)//��ʼ��
			H.elem[i] = NULLKEY;
	}
}
int Hash(int key) {//ɢ�к���
	return key % m;
}
void Inserthash(hashtable& H,int key) {//����key��hash������
	int add = Hash(key);
	while (H.elem[add] != NULLKEY) {
		add = (add + 1) % m;//����̽����ɢ��
	}
	H.elem[add] = key;
}
int Search_hash(hashtable H, int key, int& p) {//��p���ش���Ԫ��λ��
	p = Hash(key);
	while (H.elem[p] != NULLKEY && H.elem[p] != key) {
		p = (p + 1) % m;
	}
	if (H.elem[p] == key)
		return p;//������λ��
	else
		return -1;//��ʾû�鵽��Ԫ��
}
int main() {
	int key, p, i;
	hashtable H;
	inithash(H);
	for (i = 0; i < 5;i++) {
		cin >> key;
		Inserthash(H, key);
	}
	Search_hash(H, 3, p);
	cout << p << endl;
	cout << H.elem[p] << endl;
}
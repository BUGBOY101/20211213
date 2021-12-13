#define	_CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#define hashsize 10//哈希表长度
#define NULLKEY -32768
typedef int elemtype;
typedef struct {
	elemtype* elem;//hash数组
	int count;//当前哈希数组元素个数
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
		for (int i = 0; i < H.count; i++)//初始化
			H.elem[i] = NULLKEY;
	}
}
int Hash(int key) {//散列函数
	return key % m;
}
void Inserthash(hashtable& H,int key) {//插入key到hash数组内
	int add = Hash(key);
	while (H.elem[add] != NULLKEY) {
		add = (add + 1) % m;//线性探查再散列
	}
	H.elem[add] = key;
}
int Search_hash(hashtable H, int key, int& p) {//用p返回待查元素位置
	p = Hash(key);
	while (H.elem[p] != NULLKEY && H.elem[p] != key) {
		p = (p + 1) % m;
	}
	if (H.elem[p] == key)
		return p;//返回其位置
	else
		return -1;//表示没查到该元素
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
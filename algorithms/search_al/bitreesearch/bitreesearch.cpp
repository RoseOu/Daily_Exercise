#include <iostream>
using namespace std;

typedef int KeyType;

typedef struct{
    KeyType key;
} ElemType;

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

void Insert_BST(BiTree &T,KeyType e){
	BiTNode *s,*p,*f;

	//在以T为根指针的二叉排序树中插入记录e
	s=new BiTNode;
	s->data.key=e;
	s->lchild=NULL;
	s->rchild=NULL;

	if(!T){
		T=s;
	}else{
		p=T;
		while(p){
			if(e<p->data.key){
				f=p;
				p=p->lchild;
			}else{
				f=p;
				p=p->rchild;
			}
		}
		if(e<f->data.key){
			f->lchild=s;
		}else{
			f->rchild=s;
		}
	}
}

//访问结点
void visit(BiTree T){
    cout << T->data.key << " ";
}

//先序遍历二叉树
void Preorder(BiTree T,void(*visit)(BiTree)){
	if(T){
		visit(T);
		Preorder(T->lchild,visit);
		Preorder(T->rchild,visit);
	}
}

bool Search_BST(BiTree T, KeyType kval,BiTree &p,BiTree &f){
	p=T;
	while(p){
		if(kval==p->data.key){
			return true;
		}else if(kval<p->data.key){
			f=p;
			p=p->lchild;
		}else{
			f=p;
			p=p->rchild;
		}
	}
	return false;
}

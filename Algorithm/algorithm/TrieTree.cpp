#include "TrieTree.h"
void TrieTree::insert( TrieNode* root, const char* s )
{
	if(root==NULL||*s=='\0')
		return;

	TrieNode *p=root;
	while(*s != '\0')
	{
		if(p->next[*s-'a']==NULL)        //如果不存在，则建立结点
		{
			TrieNode* temp=(TrieNode *)malloc(sizeof(TrieNode));
			for(int i = 0; i < MAX; i++)
			{
				temp->next[i]=NULL;
			}
			temp->isStr=false;
			p->next[*s-'a']=temp;
			p=p->next[*s-'a'];  
		}  
		else
		{
			p=p->next[*s-'a'];
		}
		s++;
	}
	p->isStr=true;           //单词结束的地方标记此处可以构成一个单词 
}

int TrieTree::search( TrieNode* root, const char* s )
{
	TrieNode *p=root;
	while(p!=NULL&&*s!='\0')
	{
		p=p->next[*s-'a'];
		s++;
	}
	return (p!=NULL&&p->isStr==true);      //在单词结束处的标记为true时，单词才存在 
}

void TrieTree::del( TrieNode* root )
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		if(root->next[i]!=NULL)
		{
			del(root->next[i]);
		}
	}
	free(root);
}

void TrieTree::test( void )
{
	int i;
	int n,m;                              //n为建立Trie树输入的单词数，m为要查找的单词数
	char s[100];
	TrieNode* root= (TrieNode*)malloc(sizeof(TrieNode));
	for(i = 0; i < MAX; i++)
	{
		root->next[i]=NULL;
	}
	root->isStr=false;
	scanf("%d",&n);
	getchar();
	for( i = 0; i < n; i++)                 //先建立字典树
	{
		scanf("%s",s);
		insert(root,s);
	}
	while(scanf("%d",&m)!=EOF)
	{
		for(i = 0; i < m; i++)                 //查找
		{
			scanf("%s",s);
			if(search(root,s)==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		printf("\n");  
	}
	del(root);                         //释放空间很重要
}


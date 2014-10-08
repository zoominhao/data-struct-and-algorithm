#include "TrieTree.h"
void TrieTree::insert( TrieNode* root, const char* s )
{
	if(root==NULL||*s=='\0')
		return;

	TrieNode *p=root;
	while(*s != '\0')
	{
		if(p->next[*s-'a']==NULL)        //��������ڣ��������
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
	p->isStr=true;           //���ʽ����ĵط���Ǵ˴����Թ���һ������ 
}

int TrieTree::search( TrieNode* root, const char* s )
{
	TrieNode *p=root;
	while(p!=NULL&&*s!='\0')
	{
		p=p->next[*s-'a'];
		s++;
	}
	return (p!=NULL&&p->isStr==true);      //�ڵ��ʽ������ı��Ϊtrueʱ�����ʲŴ��� 
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
	int n,m;                              //nΪ����Trie������ĵ�������mΪҪ���ҵĵ�����
	char s[100];
	TrieNode* root= (TrieNode*)malloc(sizeof(TrieNode));
	for(i = 0; i < MAX; i++)
	{
		root->next[i]=NULL;
	}
	root->isStr=false;
	scanf("%d",&n);
	getchar();
	for( i = 0; i < n; i++)                 //�Ƚ����ֵ���
	{
		scanf("%s",s);
		insert(root,s);
	}
	while(scanf("%d",&m)!=EOF)
	{
		for(i = 0; i < m; i++)                 //����
		{
			scanf("%s",s);
			if(search(root,s)==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		printf("\n");  
	}
	del(root);                         //�ͷſռ����Ҫ
}


#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>

// �����յĹ�ϣ��
HashMap* HashMap_create() {
	return (HashMap*)calloc(1, sizeof(HashMap));
}

void HashMap_destroy(HashMap* map) {
	// �ͷ����н��
	for (int i = 0; i < N; i++) {
		Entry* curr = map->table[i];
		while (curr != NULL) {
			// �����̽��
			Entry* next = curr->next;
			free(curr);
			curr = next;
		}
	}
	// �ͷ�HashMap�ṹ��
	free(map);
}

int hash(char* key)
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % N;
}

V HashMap_get(HashMap* map, K key) {
	// ����key��ȡ����
	int idx = hash(key);
	// ��������
	Entry* curr = map->table[idx];
	while (curr != NULL) {
		// �ж�key�Ƿ����
		if (strcmp(key, curr->key) == 0) {
			return curr->val;
		}
		curr = curr->next;
	}
	// ������������ key
	return -1;
}

V HashMap_put(HashMap* map, K key, V val) {
	// ����key��ȡ����
	int idx = hash(key);
	// ��������
	Entry* curr = map->table[idx];
	while (curr != NULL) {
		// �ж�key�Ƿ����
		if (strcmp(key, curr->key) == 0) {
			V oldValue = curr->val;
			curr->val = val;
			return oldValue;
		}
		curr = curr->next;
	}
	// ������������ key, ��ӽ�㣬ͷ�巨
	// ������ֵ��
	Entry* entry = (Entry*)malloc(sizeof(Entry));
	if (entry == NULL) {
		printf("Error: malloc failed in HashMap_put.\n");
		exit(1);
	}
	entry->key = key;
	entry->val = val;
	entry->next = map->table[idx];
	// ���������ͷ�ڵ�
	map->table[idx] = entry;
	return -1;
}

V HashMap_remove(HashMap* map, K key) {
	// ����key��ȡ����
	int idx = hash(key);
	// ��������
	Entry* prev = NULL;
	Entry* curr = map->table[idx];
	while (curr != NULL) {
		// �ж�key�Ƿ����
		if (strcmp(key, curr->key) == 0) {
			// ɾ�����
			if (prev == NULL) {
				map->table[idx] = curr->next;
			}
			else {
				prev->next = curr->next;
			}
			// �ͷſռ�
			V removeValue = curr->val;
			free(curr);
			return removeValue;
		}
		prev = curr;
		curr = curr->next;
	}
	// ������������ key
	return -1;
}
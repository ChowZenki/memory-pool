#ifndef __MEMPOOL_H__
#define __MEMPOOL_H__

/* 
 * customization area
 */
#define DEBUG_PRINT_ON	1
#define mp_malloc(x)	malloc(x)
#define mp_free(x)	free(x)

typedef int		mp_i32;
typedef char		mp_i8;
typedef unsigned int	mp_u32;
typedef unsigned char	mp_u8;

struct item_t {
	int a;
	int b;
	int c;
	int d;
	int e;
};

typedef struct item_t	elem_t;
typedef int		status_t;

/* 
 * memory pool definition
 * note: on 64-bit machine, a pointer is 8 bytes (64 bit)
 *       memory will be aligned by 8-byte
 */
struct mp_mem_head_t {
	struct mp_node_t *p_node_first;
	struct mp_node_t *p_node_tail;
	mp_u32 size;
	mp_u32 used_node_num;
	mp_u32 max_node_num;
};

struct mp_node_t {
	struct mp_node_t *p_prev;
	mp_u32 used;
	elem_t data;
	struct mp_node_t *p_next;
};


struct mp_mem_head_t *mp_alloc(mp_i32 **pp_mem_base, mp_u32 max_node_num);
status_t mp_clean(mp_i32 *p_mem_base);
struct mp_node_t *mp_new_node(mp_i32 *p_mem_base);
status_t mp_del_node(mp_i32 *p_mem_base, struct mp_node_t *p_node);


#endif /* __MEMPOOL_H__ */

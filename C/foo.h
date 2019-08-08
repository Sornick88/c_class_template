/* Define to prevent recursive inclusion */
#ifndef __FOO_H
#define __FOO_H

/*Includes*/

/*Exported defines*/
// clang-format off

// clang-format on
/*Exported macro*/
// clang-format off

// clang-format on
/*Exported types*/
typedef _tag_foo_str_type_t
{
	char * data;
	uint32_t 	str_len
}	foo_str_type_t;
// clang-format off
typedef void * (*foo_init_t)(void * p_context);
typedef void (*foo_deinit_t)(void * p_context);

typedef uint32_t (*foo_read_data_t)(void const * p_context, 
                uint32_t * p_data);
typedef uint32_t (*foo_write_data_t)(void * p_context, 
                uint32_t const * p_data);
								
typedef uint32_t (*foo_read_str_t)(void const * p_context, 
                foo_str_type_t * p_str);
typedef uint32_t (*foo_write_str_t)(void * p_context, 
                foo_str_type_t const * p_str);
// clang-format on
typedef struct _tag_foo_m_list_t
{
	foo_init_t 	  		init;
	foo_deinit_t 			deinit;
	foo_read_data_t	  read_data;
	foo_read_str_t		read_str;
	foo_write_data_t	write_data;
	foo_write_str_t		write_str;
}	foo_m_list_t;

extern const foo_m_list_t foo_m_list;
/*Exported constants*/
/*Exported functions prototypes*/

#endif /*__FOO_H*/
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
// clang-format off
typedef void * (foo_init_t)(void * p_context);
typedef void (foo_deinit_t)(void * p_context);
typedef uint32_t (foo_io_t)(void * p_context, 
                char * p_data, uint32_t data_len);

// clang-format on
typedef struct _tag_foo_m_list_t
{
	foo_init_t 	  init;
	foo_deinit_t 	deinit;
	foo_io_t	    read;
	foo_io_t	    write;
}	foo_m_list_t;

extern const foo_m_list_t foo_m_list;
/*Exported constants*/
/*Exported functions prototypes*/

#endif /*__FOO_H*/
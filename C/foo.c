/*Includes*/
#include <foo.h>

/*Private defines*/
// clang-format off

// clang-format on
/*Private types*/
typedef struct _tag_foo_data_t
{
  uint32_t data;
} foo_data_t;
/*Private functions prototypes*/
static void *   foo_init(void * p_context);
static void     foo_deinit(void * p_context);
static uint32_t foo_read(void * p_context, 
                char * p_data, uint32_t data_len);
static uint32_t foo_write(void * p_context, 
                char * p_data, uint32_t data_len);
/*Exported constants*/
const foo_m_list_t foo_m_list = 
{
  .init     = foo_init,
  .deinit   = foo_deinit,
  .read     = foo_read,
  .write    = foo_write,
};
/*External variables*/

/*Private variables*/

/*Private macro*/
// clang-format off

// clang-format on
/*Private constants*/

/*Private functions*/
static void *   foo_init(void * p_context)
{
  return malloc(sizeof(foo_data_t));
}
static void     foo_deinit(void * p_context)
{
  free(p_context);
}
static uint32_t foo_read(void * p_context, 
                char * p_data, uint32_t data_len)
{
  uint32_t ret_val = 0;
  if (p_context && p_data && data_len == sizeof(foo_data_t))
  {
    ((foo_data_t*)p_data)->data = ((foo_data_t*)p_context)->data;
    ret_val = 1;
  }
  else
  {
    ret_val = -1;
  }
  return ret_val;
}
static uint32_t foo_write(void * p_context, 
                char * p_data, uint32_t data_len)
{
  uint32_t ret_val = 0;
  if (p_context && p_data && data_len == sizeof(uint32_t))
  {
    ((foo_data_t*)p_context)->data = ((foo_data_t*)p_data)->data;
    ret_val = 1;
  }
  else
  {
    ret_val = -1;
  }
  return ret_val;
}
/*Public functions*/

/******************************* END_OF_FILE **********************************/
/*Includes*/
#include <foo.h>

/*Private defines*/
// clang-format off

// clang-format on
/*Private types*/
typedef struct _tag_foo_data_t
{
  /*use method list pointer as obj type veryfication*/
  foo_m_list_t  * p_m_list;
  /*to use custom types they must be declared in .h file*/
  foo_str_type_t  str; 
  /*standart type*/
  uint32_t data;
} foo_data_t;
/*Private functions prototypes*/
static void * init(void * p_context);
static void   deinit(void * p_context);

static uint32_t read_data(void const * p_context, 
                uint32_t * p_data);
static uint32_t read_str(void const * p_context, 
                foo_str_type_t * p_data);

static uint32_t write_data(void * p_context, 
                uint32_t const * p_data);
static uint32_t write_str(void * p_context, 
                foo_str_type_t const * p_data);

/*Exported constants*/
const foo_m_list_t foo_m_list = 
{
  .init         = init,
  .deinit       = deinit,
  .read_data    = read_data,
  .read_str     = read_str,
  .write_data   = write_data,
  .write_str    = write_str,
};
/*External variables*/

/*Private variables*/

/*Private macro*/
// clang-format off

// clang-format on
/*Private constants*/

/*Private functions*/
static void * init(void * p_context)
{
  foo_data_t * p_foo = NULL;
  p_foo = malloc(sizeof(foo_data_t));
  if (!p_foo)
    return NULL;

  p_foo->p_m_list = &foo_m_list;
  p_foo->data = 0;
  p_foo->str.str = NULL;
  p_foo->str.str_len = 0;

  return (void *)p_foo;
}

static uint32_t deinit(void * p_context)
{
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return -1;

  free(p_context);

  return 1;
}

static uint32_t read_data(void const * p_context, 
                uint32_t * p_data)
{
  if (!p_context && !p_data)
    return -1;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return -1;
  
  *p_data = ((foo_data_t *)p_context)->data;

  return 1;
}

static uint32_t read_str(void const * p_context, 
                foo_str_type_t * p_str)
{
  if (!p_context && !p_data)
    return -1;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return -1;

  p_str->data = ((foo_data_t*)p_context)->str.data;
  p_str->str_len = ((foo_data_t*)p_context)->str.str_len;

  return 1;
}

static uint32_t write_data(void * p_context, 
                uint32_t const * p_data)
{
  if (!p_context && !p_data)
    return -1;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return -1;

  ((foo_data_t*)p_context)->data = *p_data;

  return 1;
}

static uint32_t write_str(void * p_context, 
                foo_str_type_t * p_str)
{
  if (!p_context && !p_data)
    return -1;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return -1;

  ((foo_data_t*)p_context)->str.data = p_str->data;
  ((foo_data_t*)p_context)->str.str_len = p_str->str_len;

  return 1;
}
/*Public functions*/

/******************************* END_OF_FILE **********************************/
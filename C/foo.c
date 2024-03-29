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
  int data;
} foo_data_t;
/*Private functions prototypes*/
static void * init(void * p_context);
static int   deinit(void * p_context);

static int read_data(void const * p_context, 
                int * p_data);
static int read_str(void const * p_context, 
                foo_str_type_t * p_data);

static int write_data(void * p_context, 
                int const * p_data);
static int write_str(void * p_context, 
                foo_str_type_t const * p_str);

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
  foo_data_t * p_foo = 0;
  p_foo = malloc(sizeof(foo_data_t));
  if (!p_foo)
    return 0;

  p_foo->p_m_list = &foo_m_list;
  p_foo->data = 0;
  p_foo->str.data = 0;
  p_foo->str.str_len = 0;

  return (void *)p_foo;
}

static int deinit(void * p_context)
{
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return ERROR;

  free(p_context);

  return OK;
}

static int read_data(void const * p_context, 
                int * p_data)
{
  if (!p_context && !p_data)
    return ERROR;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return ERROR;
  
  *p_data = ((foo_data_t *)p_context)->data;

  return OK;
}

static int read_str(void const * p_context, 
                foo_str_type_t * p_str)
{
  if (!p_context || !p_str)
    return ERROR;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return ERROR;

  p_str->data = ((foo_data_t*)p_context)->str.data;
  p_str->str_len = ((foo_data_t*)p_context)->str.str_len;

  return OK;
}

static int write_data(void * p_context, 
                int const * p_data)
{
  if (!p_context && !p_data)
    return ERROR;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return ERROR;

  ((foo_data_t*)p_context)->data = *p_data;

  return OK;
}

static int write_str(void * p_context, 
                foo_str_type_t const * p_str)
{
  if (!p_context || !p_str)
    return ERROR;
  
  /*non foo class pointer*/
  if (((foo_data_t *)p_context)->p_m_list != &foo_m_list)
    return ERROR;

  ((foo_data_t*)p_context)->str.data = p_str->data;
  ((foo_data_t*)p_context)->str.str_len = p_str->str_len;

  return OK;
}
/*Public functions*/

/******************************* END_OF_FILE **********************************/
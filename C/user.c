/*Includes*/
#include <foo.h>

/*Private defines*/
// clang-format off

// clang-format on
/*Private types*/
typedef struct _tag_user_data_t
{
  int data;
} user_data_t;
/*Private functions prototypes*/

/*Exported constants*/

/*External variables*/

/*Private variables*/
void * p_foo = 0;
int var = 32;
user_data_t user_data;
/*Private macro*/
// clang-format off

// clang-format on
/*Private constants*/

/*Private functions*/

/*Public functions*/
int user_main(void)
{
  p_foo = foo_m_list.init(0);
  if (p_foo != 0)
  {
    if (foo_m_list.write_data(p_foo, &var))
    {
      foo_m_list.read_data(p_foo, &user_data.data);
      foo_m_list.deinit(p_foo);
    }
  }
  return 0;
}
/******************************* END_OF_FILE **********************************/
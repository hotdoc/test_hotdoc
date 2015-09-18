#ifndef TEST_GREETER_H_
#define TEST_GREETER_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define TEST_TYPE_GREETER (test_greeter_get_type ())
#define TEST_IS_GREETER(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), TEST_TYPE_GREETER))
#define TEST_IS_GREETER_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), TEST_TYPE_GREETER))
#define TEST_GREETER(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), TEST_TYPE_GREETER, TestGreeter))
#define TEST_GREETER_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), TEST_TYPE_GREETER, TestGreeterClass))

typedef struct _TestGreeter TestGreeter;
typedef struct _TestGreeterClass TestGreeterClass;

/**
 * TestGreeterTranslateFunction:
 * @greeter: The #TestGreeter asking for translation
 * @word: The word to translate
 *
 * This function shall return the translation of @word in any target language,
 * so that @greeter knows how to greet properly.
 *
 * Returns: (transfer full): The translation of @word
 */
typedef gchar* (* TestGreeterTranslateFunction) (TestGreeter *greeter, const gchar *word);

/**
 * GreetCountUnit:
 *
 * The unit in which greets are counted.
 */
typedef gint GreetCountUnit;

/**
 * TestGreeterClass:
 * @do_greet: Subclasses can implement this to greet themselves
 */
struct _TestGreeterClass
{
  GObjectClass parent_class;

  void (*do_greet) (TestGreeter *greeter, const gchar *name, TestGreeterTranslateFunction func);
};

/**
 * TestGreeter:
 * @greet_count: The number of times the greeter greeted.
 *
 * The #TestGreeter structure. Use the functions to update
 * the variables;
 */
struct _TestGreeter
{
  GObject parent;
  GreetCountUnit greet_count;
  /*< private >*/
  gboolean count_greets;
};

GType test_greeter_get_type ();

/**
 * test_greeter_greet_count:
 *
 * The number of times the greeter greeted.
 */
extern GreetCountUnit test_greeter_greet_count;

void test_greeter_greet (TestGreeter *self,
                         const gchar *name,
                         TestGreeterTranslateFunction translator);

/**
 * TEST_GREETER_VERSION:
 *
 * The current version of the #TestGreeter
 */
#define TEST_GREETER_VERSION "1.0"

/**
 * TEST_GREETER_UPDATE_GREET_COUNT:
 *
 * Increments the greet counter.
 *
 * MT safe.
 *
 * Returns: void
 */
#define TEST_GREETER_UPDATE_GREET_COUNT(greeter) \
G_STMT_START {                                   \
  g_atomic_int_inc (&greeter->greet_count);      \
  g_atomic_int_inc (&test_greeter_greet_count);               \
} G_STMT_END;

/**
 * TestGreeterLanguage:
 * @TEST_GREETER_ENGLISH: Shakespeare language
 * @TEST_GREETER_FRENCH: Moliere Language
 *
 * A language for greeting.
 */
typedef enum {
  TEST_GREETER_ENGLISH,
  TEST_GREETER_FRENCH
} TestGreeterLanguage;

TestGreeterTranslateFunction
test_greeter_get_translate_function (TestGreeter *greeter, TestGreeterLanguage language);

G_END_DECLS

#endif

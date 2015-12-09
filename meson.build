project('Hotdoc-Test', 'c')
gnome = import ('gnome')

glib_dep = dependency('glib-2.0')
gobject_dep = dependency('gobject-2.0')

sources = ['test-greeter.c', 'test-other-file.c']
headers = ['test-greeter.h', 'test-other-file.h']

test_lib = shared_library('test_lib',
		          sources,
		          install: true,
		          dependencies: [glib_dep, gobject_dep],
		          c_args: ['-Wno-pedantic'],
		         )

gir = gnome.generate_gir(test_lib,
  sources : sources + headers,
  nsversion : '1.0',
  namespace : 'Test',
  symbol_prefix : 'test_',
  identifier_prefix : 'Test',
  export_packages : 'test',
  includes : ['GObject-2.0'],
  install : true
)

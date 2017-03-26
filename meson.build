project('Hotdoc-Test', 'c')
gnome = import ('gnome')

glib_dep = dependency('glib-2.0')
gobject_dep = dependency('gobject-2.0')

sources = ['test-greeter.c', 'test-gobject-macros.c', 'test-other-file.c', 'test-interface.c', 'c_subfolder/test_subfolder.c']
headers = ['test-greeter.h', 'test-gobject-macros.h', 'test other-file.h', 'test-interface.h', 'c_subfolder/test_subfolder.h']

incdir = include_directories('test_include')

test_lib = shared_library('testlib',
		          sources,
		          install: true,
		          dependencies: [glib_dep, gobject_dep],
		          c_args: ['-Wno-pedantic'],
			  include_directories: incdir,
		         )

gir = gnome.generate_gir(test_lib,
  sources : sources + headers,
  nsversion : '1.0',
  namespace : 'Test',
  symbol_prefix : 'test',
  identifier_prefix : 'Test',
  export_packages : 'test',
  includes : ['GObject-2.0'],
  install : true
)

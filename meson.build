project('Hotdoc-Hello-Test', 'c')
gnome = import ('gnome')

glib_dep = dependency('glib-2.0')
gobject_dep = dependency('gobject-2.0')

sources = ['hello.c']
ges = shared_library('hello-test',
		     sources,
		     install: true,
		     dependencies: [glib_dep, gobject_dep],
		     c_args: ['-Wno-pedantic'],
		    )

project('Hotdoc-Test', 'c')
gnome = import ('gnome')
hotdoc = import ('hotdoc')

glib_dep = dependency('glib-2.0')
gobject_dep = dependency('gobject-2.0')

sources = ['test-greeter.c']
headers = ['test-greeter.h']

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

markdown_files = ['index.markdown',
		  'test-api.markdown',
		  'test-greeter.markdown',
		  'org-test-greeter.markdown',
		  'gobject-api.markdown',
		 ]

markdown_index = '@0@/@1@'.format(meson.current_source_dir(), 'index.markdown')
gi_index = 'gobject-api.markdown'


dbus_sources = ['@0@/@1@'.format(meson.current_source_dir(), 'org.test.greeter.xml')]
python_sources = ['@0@/@1@'.format(meson.current_source_dir(), 'python_example.py')]

c_sources = ['@0@/@1@'.format(meson.current_source_dir(), 'test-greeter.c'),
	     '@0@/@1@'.format(meson.current_source_dir(), 'test-greeter.h')]

gir_file = '@0@/@1@'.format(meson.current_build_dir(), 'Test-1.0.gir')

doc = hotdoc.generate_doc (input: sources + headers + markdown_files,
			   output: 'html',
			   output_format: 'html',
			   depends: gir[0],
			   library: test_lib,
			   index: markdown_index,
			   extra_args: ['c-extension', '--clang-options', '-I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include',
			   		'--c-sources', c_sources, '--end-c-sources',
			   		'gi-extension', '--gir-file', gir_file,
			   		'--languages', ['c', 'python', 'javascript'], '--major-version', '1.0',
					'--gi-index', gi_index
				       ]
			   )

gen_html = '@0@/@1@'.format(meson.current_build_dir(), 'html')
ref_html = '@0@/@1@'.format(meson.current_source_dir(), 'html_reference')

check_doc = find_program ('check_doc.py')
test ('check_doc', check_doc,
      args: [ref_html, gen_html])

This is a test project for [hotdoc](https://github.com/MathieuDuponchelle/hotdoc)

To build the library, use:

```shell
$ mkdir build
$ cd build
$ meson ..
$ ninja
```

To run the tests, use:

```shell
ninja test
```

You can then take a look at the result of the test in build/meson-logs/testlog.txt ,
if there are any differences you can check the files in 'html' suffixed with
diff.html, either with a text editor by looking for `<ins>` and `<del>` tags,
or with a web browser.

Once you made sure the differences were legitimate, you can update the files
in html_reference and make a pull request.

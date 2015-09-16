#!/usr/bin/env python2

import sys, os

reload(sys)
sys.setdefaultencoding('utf8')

from htmltreediff import diff
from lxml import etree

def diff_html(ref_path, gen_path):
    res = True

    with open(ref_path) as ref_file:
        ref_html = ref_file.read()
    with open(gen_path) as gen_file:
        gen_html = gen_file.read()

    result = diff(ref_html, gen_html, cutoff=0.0, pretty=True)

    with open ('result.html', 'w') as f:
        f.write (result)

    parser = etree.HTMLParser()
    tree = etree.parse ('result.html', parser=parser)
    root = tree.getroot()

    inserted = root.findall(".//ins")
    deleted = root.findall(".//del")

    if inserted or deleted:
        diff_filename = '%s.diff.html' % gen_path
        sys.stderr.write ("There's a difference, you can open %s"
                " with your browser to look at it" % diff_filename)
        with open (diff_filename, 'w') as f:
            f.write (result)
        res = False

    os.unlink ('result.html')

    return res

if __name__=='__main__':
    ref_html_folder = sys.argv[1]
    gen_html_folder = sys.argv[2]
    result = 0

    for filename in os.listdir (ref_html_folder):
        path = os.path.join (ref_html_folder, filename)
        if os.path.isdir(path):
            folder = os.path.join (ref_html_folder, path)
            for filename2 in os.listdir (folder):
                split = os.path.splitext(filename2)
                if len (split) < 2 or split[1] != '.html':
                    continue

                ref_path = os.path.join (ref_html_folder, filename, filename2)
                gen_path = os.path.join (gen_html_folder, filename, filename2)
                if not diff_html (ref_path, gen_path):
                    result += 1

    print "exiting with result", result
    sys.exit(result)

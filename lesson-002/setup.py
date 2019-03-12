from distutils.core import setup, Extension
from glob import glob

lesson2 = Extension('lesson2',
    language            = 'c++',
    include_dirs        = ['.', ],
    libraries           = [],
    library_dirs        = [],
    sources             = glob('*.cpp'),
    extra_compile_args  = [],
    extra_link_args     = [],
)

setup(name              = 'lesson2',
    version             = '0.1',
    description         = 'Lesson 2',
    url                 = 'https://github.com/maxdoom-com/extend-python-with-cplusplus/',
    ext_modules         = [lesson2,]
)

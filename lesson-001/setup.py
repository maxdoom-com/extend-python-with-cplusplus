from distutils.core import setup, Extension
from glob import glob

lesson1 = Extension('lesson1',
    language            = 'c++',
    include_dirs        = ['.', ],
    libraries           = [],
    library_dirs        = [],
    sources             = glob('*.cpp'),
    extra_compile_args  = [],
    extra_link_args     = [],
)

setup(name              = 'lesson1',
    version             = '0.1',
    description         = 'Lesson 1',
    url                 = 'https://github.com/maxdoom-com/extend-python-with-cplusplus/',
    ext_modules         = [lesson1,]
)

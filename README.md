cliqz-port
==========

FreeBSD [Ports][4] script for Cliqz Browser.

You can find more information about Cliqz Brower [here][1]

Installation
------------

Copy `www/cliqz` folder to `/usr/ports` directory.

NOTE: If your ports directory is different from above, copy to the respective
place.

Usage
-----

Once you have copied the folder, install it as you would do for any port.

`$ cd /usr/ports/www/cliqz`<br>
`$ make install clean`

For a list of dependencies for the build check [here][2]

Credits
-------

* Cliqz Browser is developed and maintained by [Cliqz GmBH][3]
* Thanks to `@aashiks` and `@dbalan` for helping me come up with port package and
  for doing builds to test out the port.
* Thanks to `@ppaeps` for a machine to do and test the port development and
  testing out / fixing / committing the port.

License
-------

BSD 2-clause. See LICENSE.

[1]: http://cliqz.com/
[2]: https://github.com/cliqz-oss/browser-f/
[3]: https://cliqz.com/en/
[4]: https://www.freshports.org/www/cliqz

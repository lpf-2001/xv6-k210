import unittest
import pexpect
import sys

class QemuTest(unittest.TestCase):
    def setUp(self):
        self.p = pexpect.spawn("make run platform=qemu")
        self.p.delaybeforesend = None
        #self.p.logfile = sys.stdout.buffer
        self.p.ignorecase = True

    def tearDown(self):
        self.p.terminate()


class BehaviorTest(QemuTest):
    def test_getpid(self):
        self.p.expect('-> / \$ ', timeout=3)
        self.p.sendline('getpid')
        self.p.expect('getpid success.')
        self.p.expect(r'pid = (\d+)')
        pid = int(self.p.match.group(1))
        self.assertTrue(pid > 2)


class StringTest(unittest.TestCase):
    def test_upper(self):
        self.assertEqual("foo".upper(), "FOO")

    def test_lower(self):
        self.assertEqual("foo".upper(), "FOO")


if __name__ == "__main__":
    unittest.main()

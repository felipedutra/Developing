"""Copyright 2022 Google LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""
import unittest

from update_smime_cert import update_smime_cert


class TestUpdateSmimeCert(unittest.TestCase):
    """Unit test class for snippets"""

    @classmethod
    def test_update_smime_cert(cls):
        """test update smime cert"""
        result = update_smime_cert(user_id='xyz', send_as_email='yzx',
                                   cert_filename='abc', cert_password='abc',
                                   expire_dt='cde')
        cls.assertIsNotNone(cls, result)


if __name__ == '__main__':
    unittest.main()

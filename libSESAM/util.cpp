/*

    Copyright (c) 2015-2018 Oliver Lau <ola@ct.de>, Heise Medien GmbH & Co. KG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <QDebug>
#include "util.h"


QString fingerprintify(const QByteArray &ba) {
  const QByteArray &baHex = ba.toHex();
  QByteArray result = baHex;
  for (int i = baHex.size() - 2; i > 0; i -= 2)
    result.insert(i, ':');
  return result;
}


#if defined(Q_CC_GNU)
void SecureErase(QString str)
{
  for (QString::iterator i = str.begin(); i != str.end(); ++i)
    *i = 0;
  str.clear();
}
#endif


/*!
 * \brief shuffle
 *
 * Fisher-Yates shuffling of a string.
 *
 * \param s String to be shuffled
 * \return shuffled string
 */

QString shuffled(const QString& s)
{
  QString result = s;
  int n = result.count();
  QChar *c = result.data();
  while (n) {
    int j = qrand() % n--;
    QChar tmp = *(c + n);
    *(c + n) = *(c + j);
    *(c + j) = tmp;
  }
  return result;
}


/*!
 * \brief shuffle
 *
 * Fisher-Yates shuffling of a byte array.
 *
 * \param s byte array to be shuffled
 * \return shuffled byte array
 */
QByteArray shuffled(const QByteArray& ba)
{
  QByteArray result = ba;
  int n = result.count();
  char *c = result.data();
  while (n) {
    int j = qrand() % n--;
    char tmp = *(c + n);
    *(c + n) = *(c + j);
    *(c + j) = tmp;
  }
  return result;
}


bool containsAll(const QString &haystack, const QString &needles) {
  bool ok = true;
  foreach (QChar needle, needles) {
    if (!haystack.contains(needle)) {
      ok = false;
      break;
    }
  }
  return ok;
}


bool containsAny(const QString &haystack, const QString &needles) {
  foreach (QChar needle, needles)
    if (haystack.contains(needle))
      return true;
  return false;
}

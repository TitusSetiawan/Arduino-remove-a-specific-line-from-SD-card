
void findText()
{
  char ch;
  String tempText;

  File myFile = SD.open("sample.txt");
  Serial.println("Remove Text: " + removeText);
  while (myFile.available())
  {
    ch = myFile.read();
    if (ch == '\n')
    {
      String tempNIM = String(readText[indexCharX]);
      if (tempNIM == removeText)
      {
        Serial.println("text found, result: " + String(readText[indexCharX]) + String(ch));
        flagDeleted = indexCharX;
        delay(500);
      }
      else
      {
        Serial.println(String(readText[indexCharX]) + " not found, result: -");
        delay(500);
      }
      indexCharX++;
    }
    else
    {
      tempText += ch;
      indexCharY++;
      if (indexCharY == 4)
      {
        Serial.println(tempText);
        readText[indexCharX] = tempText;
        indexCharY = 0;
        tempText = "";
      }
    }
  }
  myFile.close();
  Serial.println("DONE");

}

void createFile()
{
  Serial.println("Delete text with specific line");
  SD.remove("sample.txt");
  File myFile = SD.open("sample.txt", FILE_WRITE);
  if (myFile)
  {
    for (int i = 0; i <= indexCharX; i++)
    {
      if (i == flagDeleted)
      {
        Serial.println("Continue");
        continue;
      }
      else
      {
        Serial.println("write");
        myFile.print(readText[i] + '\n');
      }
    }

  }
  else
  {
    Serial.println("Failed");
  }
  myFile.close();
}

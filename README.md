# SSI

## Ссылки на чертежи

[Сама кормушка](https://www.thingiverse.com/thing:2959685/comments)
[Подшипник для неё](https://www.thingiverse.com/thing:4628063/comments)

## Комплектующие

Список всех комплектующих, используемых в проекте

- МК ESP-32 38 pin
- Шаговый мотор 28BYJ-48 с драйвером ULN2003A
- Микросхема реального времени DS3231
- Пара кнопок
- Пара светодиодов

## Документация на железо

[ESP-32-WROOM](sources/esp32-wroom_datasheet.pdf)
[ESP Pinout](sources/ESP-32-Dev-Kit-C-V2-Pinout.png)
[DS3231](sources/04-DS3231SN-T-R.pdf)
[ULN2003A](sources/ULN200xA.pdf)
[28BYJ-48](sources/28BYJ-48.pdf)

## Документация на ПО

Список документация на технологии, используемые в проекте:

- MQTT - брокер обмена сообщениями между устройствами
  - [MQTTnet](https://github.com/dotnet/MQTTnet)
  - [Пример](https://voltiq.ru/cloud-mqtt-mosquitto-broker-access-anywhere-digital-ocean/)
- ASP.NET Core - кроссплатформенная среда для создания веб-приложений
  - [Оффициальная документация](https://learn.microsoft.com/ru-ru/aspnet/core/introduction-to-aspnet-core?view=aspnetcore-7.0)
  - [Razor Pages](https://learn.microsoft.com/ru-ru/aspnet/core/razor-pages/?view=aspnetcore-7.0&tabs=visual-studio)
- OpenIddict - провайдер OpenID Connect для приложений ASP.NET Core
  - [Github](https://github.com/openiddict/openiddict-core)
- PostgreSQL - open-source СУБД
  - [Npgsql](https://www.npgsql.org/efcore/)
- Nginx - HTTP и обратный прокси сервер
  - [nginx](https://nginx.org/ru/)

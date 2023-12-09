# Проект FishFeeder

Проект автоматизированной кормушки для рыбок на базе микроконтроллера ESP32 с использованием брокера сообщений [Dealgate](https://dealgate.ru/) и [Алисы](https://yandex.ru/alice).

# Начинаем

## Необходимое оборудование

Для сборки проекта необходимы следующие комплектующие:

- Микроконтролер [ESP-32 38 PIN.](https://aliexpress.ru/item/32864722159.html?sku_id=10000014440609820&spm=a2g2w.productlist.search_results.0.2dd540375Empyt)
- Шаговый мотор [28BYJ-48 с модулем ULN2003](https://aliexpress.ru/item/32906617266.html?sku_id=12000027293392609&spm=a2g2w.productlist.search_results.0.755b4464Nu0xsf)
- [Корпус и механизм кормушки](https://www.thingiverse.com/thing:2959685/files)

## Необходимое ПО

Для сборка проекта необходимо установить следующее ПО:

- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO IDE](https://platformio.org/platformio-ide)
- [Zadiq](https://zadig.akeo.ie/)

## Сборка устройства

Сборка корпуса кормушки производится по инструкции из описания [проекта](https://www.thingiverse.com/thing:2959685). Подключение микроконтроллера ESP32 и мотора на схеме:

<p align="center">
 <img width="400px" src="/pic/Scheme_МП.png" alt="qr"/>
</p>
Для подключения мотора можно изменить пины, но необходимо соотвественно изменить пины в прошивке.

## Настройка брокера Dealgate

Заходим на форму логина [Dealgate](https://dealgate.ru/login) и выполняем вход с помощью "Яндекс Войти" с того аккаунта, который будет использоваться для управлением аккаунта. При необходимости выполнить авторизацию в аккаунте яндекса.

<p align="center">
 <img width="600px" src="/pic/dealgate-login.png"/>
</p>

После входа на сайт переходим на панель устройства и создаем новое устройство.

<p align="center">
 <img width="600px" src="/pic/dealgate-create.png"/>
</p>

Заполняем обязательные поля: "Наименование", "Описание", "Комната. Тип устройства "Переключатель", MQTT Client ID - ID для нашей кормушки, его надо записать.
После создания устройства нас перебрасывает на его настройки, необходимо настроить его умение "Питание"

<p align="center">
 <img width="600px" src="/pic/dealgate-settings.png"/>
</p>

Для работы с Алисой необходимо включить "Оповещение Яндекс" и настроить MQTT Topic, куда Алиса будет писать. После чего нажимаем сохранить.

<p align="center">
 <img width="600px" src="/pic/dealgate-settings2.png"/>
</p>

После настройки устройства необходимо настроить профиль для подключения к брокеру Dealgate. Переходим в профиль пользователя и настраиваем для MQTT сервера Username и Password, их тоже надо записать и сохранить.

<p align="center">
 <img width="600px" src="/pic/dealgate-profile.png"/>
</p>

## Загрузка прошивки

Для загрузки прошивки вам понадобиться склонировать репозиторий:

```
git clone https://github.com/Killllero0/SSI
```

После этого запускаем Visual Studio Code и в панели PlatformIO выбрать пункт "Pick a folder", после чего выбрать зайти в SSI\hardware\FishFeeder и открыть папку. PlatformIO автоматически начнет подтягивать всё необходимое ПО.
В файле `settings.h` необходимо внести все те данные, которые мы настраивали на сайте dealgate.ru

<p align="center">
 <img width="600px" src="/pic/vscode-settings.h.png"/>
</p>

После внесения всех изменений можно подключать наш МК к компьютеру и загружать прошивку. Для этого переходим в панель PlatformIO и жмем Upload. Чтобы во время прошивки МК определился компьютером необходимо зажать кнопку BOOT. Если МК не определился, а в диспетчере устройств видно неопознанное устройство - необходимо с помощью Zadiq поставить на это неопознанное устройство драйвер USB Serial.

## Настройка умного дома с Алисой

Заходим в приложение "Умный дом"

<p align="center">
 <img width="600px" src="/pic/alice-start.jpg"/>
</p>
Жмем на плюс и устройства умного дома. Ищем dealgate
<p align="center">
 <img width="600px" src="/pic/alice-dealgate.jpg"/>
</p>
Жмем на Dealgate и по инструкции добавляем аккаунт Dealgate
<p align="center">
 <img width="600px" src="/pic/alice-dealgate-add.jpg"/>
</p>
После нам показываются все новые устройства, выставляем настройки для устройства
<p align="center">
 <img width="600px" src="/pic/alice-setteing.jpg"/>
</p>
После этого нам доступно управление кормушкой
<p align="center">
 <img width="600px" src="/pic/alice-yes.jpg"/>
</p>
После это все настроенно, включая и выключая кормушку в приложении Алисы она каждый раз насыпает корм

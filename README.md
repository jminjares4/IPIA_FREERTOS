# **Intelligent Portable Infrasound Array (IPIA)** :zap:

## **Status**
[![Doxygen Action](https://github.com/jminjares4/IPIA_FREERTOS/actions/workflows/main.yml/badge.svg)](https://github.com/jminjares4/IPIA_FREERTOS/actions/workflows/main.yml) [![pages-build-deployment](https://github.com/jminjares4/IPIA_FREERTOS/actions/workflows/pages/pages-build-deployment/badge.svg)](https://github.com/jminjares4/IPIA_FREERTOS/actions/workflows/pages/pages-build-deployment)

## **Description**
This is the source code of our `(Spring-Fall 2020)` capstone project for Electrical and Computer Engineering department at **`University of Texas at El Paso`** ***`(UTEP)`***.

## **Team Members**
- [Erick A Baca](https://github.com/eabaca2419)
  - Hardware testing and system integration
- [Jesus Minjares](https://github.com/jminjares4)
  - Embedded software and firmware testing
- Cynthia Oaxaca
  - Power System
- Mariano Urbina
  - Hardware design 

## **Table of Contents**
* [Firmware](https://github.com/jminjares4/IPIA_FREERTOS/tree/main/Firmware)
  * drivers
  * inc
  * ipia.c
  * main_freertos.c
* [Hardware](https://github.com/jminjares4/IPIA_FREERTOS/tree/main/Hardware)
  * schematic1.0.sch
  * images
* [Media](https://github.com/jminjares4/IPIA_FREERTOS/tree/main/media)
  * gif
  * images
  * video
* Readme

## **Requirements**
- [x] Firmware running at real-time 
- [x] Read pressure sensor at 100hertz
- [x] Wireless communication between two MCUs 
- [x] Capture system location using a GPS
- [x] Time stamp capture data
- [x] Solar tracker to find optimal postion for the battery charger 

## **IPIA Data Capture**
To visualize the data that was being capture, a python script was develop that reads the data being transmitted via the wireless communication. 
The script uses `pyserial` and `matplotlib` packages to send the capture data from the `HC-05 Module` and store it into a csv file. Here is small demostration.

<img src="media/gif/ipia_reading.gif">

* [Jesus Minjares Python Script](https://github.com/jminjares4/Plotting-Sensor-Data)
## **Solar Tracker**
<img src="media/gif/solarTracker.gif" height="750" width="500">

## **Development**
| **IPIA** | **Hardware/Software**|
| :--- | :--- |
|**Microcontroller**| ![Texas Instruments](https://img.shields.io/static/v1?label=&message=MSP432&color=696969&logoWidth=38&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGwAAAAoCAYAAAAbrx%2B3AAAKYklEQVR42u1aA5B0ORDOzpvV%2FDNr2zv4bfNs27Zt27Zt27Zt2%2Fbd99V2159Lvdm9mdNs1euqrnlJOnlJf0mnu9%2BYgAIK6P%2BkyuLixqVqyjdyuWNIwTATUO7RmLLorNvHpn53eanqyk3N4KQAsDpjqhuKi5tNQLkPWMyYqmtHJT6%2FZUzyx2QkMsoElJuAnZDovH9Caem8tcbUALDPCFgqEhnXXFjYWRWJNKBrMTjPBJQbgJE3aK7dtypi6ieXRmePi8UmNxUWdmnbHWNTv142svedGeWxRU1uUAAYwdijq%2FlcPm%2FeUn%2F4zLLYEq7MkjXlG5j%2FlwLA9upquWTj5rpDY%2FD6LxjR8zLrFqgqX3FUNDqD9VeOjH%2BkskvXlG9o%2Fj8KALsNpo53lDocLLOed5d0KbppTPI7ld%2BgsW4vE9A%2FT3EEwhcM73nF5ctG9L5rA3bOsO7njNCkkpL5WXf1qPhHKIZYN7YsOtOWv3h4zxtRuP3Gn4rAZQMz90ZALuWfN6z7BVF0Wsbp%2BeHSEb3vTy%2BLLbZWY82urDu0p%2B36UbHiSayHx%2FiF22evzuYLfV%2BY711UUBD%2B7S%2FwNxAvcboH1BUtSF0xIv7%2BQKCROwoLew7qab2az%2Bs31e25RkP1Dulk9%2B1svtTndWXhsHdlKBTawvO8NcCrA8BbAc7v4M%2B1Du0b4vdUzzOrBAj5EF1znJR3%2BgPr%2BtGJL3hArhRwp5bHFjlEwBN2nJTmi%2FzMoRunhcOhfQgYgHvFqh4ip6uJvw5rrOfW50vfAqfes19njZGWZIyo9CXnHtHj6w%2BwUxKdD9cXFbXi%2BTc6HdVDTN3VI%2BMfppPfqrXhaDMw%2BQKGk7U46r4D%2F%2Boy5F6FSCFO4S4o%2FyT176NO02RtKH8B%2FhZj74lyufWuvfvGCD0loDtzMXMw%2Fr2Q%2BQH8C%2Fjr%2FPzwC8yHmxykostHznU2bh2b%2FOWSEb1vESCWj4i33co1NWLy2PYV7MC01LbtDcc4YP12WrLzEToi2QJGolJZD2B2oK8DngyFzgtTeTJ%2Fpe8BYk5%2FQDFlgf0rfpdwTw2BFYB%2FxxiznfZR3AD5Ye82PA8FV4Mn4H2ng9c1uUjzVZQucxuAgvn7amQsNoV1K9VXbUkgLkTs5bcrj%2Bxtv0XBOry37QamqlyZLAF7gvV4nOrTLaJi6HeH9H%2BAjq%2FchSc68gRy%2BXA4%2FDbb%2BgDzLrPbsTF27KsPHenzvpZcdkKSbUVFbVZV3inJrgcJyBr1tTvRHIE9OiBrN9bucuuY1E83jU5%2Bt2h15RoK6D8JGBS9GIp1wuNwMtyTWw%2B59%2BSkfQET9iLvQOMQgQUou3EMkf0Zz61zAfVWZr3M5WGaXFSPHpS50VllZYvrKboZATIA%2BkbLAOznqRUlC6jsPw2YwwRwZZ9hZqipg6K39mlPidlsIAAY%2Bxk5TfvbJhOn7mr3fZB9jLkEM8gohOD5WT%2FnYtOWhoMo8G8BRjcfxeFkgLUIeCHjEEDayFLyZ64J87zQ0bwT0XdZMs0hZQsLwx87HmMeTzDl6WxIPChygyuQ5%2F22vA9gv7UUFXW4sv%2F2HebQaMh9D2BPgZKflbFut9zxqHiNn6L9Y2U9kei3pshVOOPmycn9RpyUWWaQUR6yG9e6OUY6AP8yYNN8uk3RQBz9Xobs0zKPBPp8pd6lnL4N4Gy8o3GaEgN4MXmPcG0oX0xP1D28HF%2FmkTKDjBjQlB4bb7%2FDBg1BT9xkT7zsT%2BpTXPhDFi1FvS5A3gs%2BT%2Fh88D18pvMDJV8iyhxvmcetxTT%2BCPO3INzIN2jifN67EuXk9MyPfpvz1NGtxyY6kDGb5YGeZXKEGnhHgNcg04P6K4diydqKdQ%2FtbbuR%2BURx%2F7OlEVDmKRLrgM0i4oKvKHW%2BDAXPB4XuoWWaLp0bFL%2B7JXsafyF7kGsJILfpXLnQMagahrqd%2BAyAbgPfDT4Xc1mO4iZXCBM8WXba15KOCSiHiTttVwImdn4QUgBYBczEqmQfD61T2xzzOR7jbMfcXZ%2BJNQtLfULkfVlSTtN82lYR971KxillYKvtmpoSClOe9WK%2BelROTKUvMYUlfZah08FMSD%2FzHA0u4hzsPvbVorKS8hozwLqHWX2T0N2W0N1e%2BF1f1h3NADBOPnS8fXFLvaaC7pLkaQxcgPKFjFfoUrON6R9xBHpRPoNj0KGg6y1j%2FoLyB5JYfZ4ZDD6zDYO%2FBUfiDoz%2FqLjd32N%2Bm6m3J%2F0%2FJ5CO8peSoHppKhbvfUgzH2kSt1M5Z7JuPMZn7KP9wO%2FLPH%2BAI3K7yCyjMnRMbDWifJhkT7rlk9G30v9n6fOTlL%2FFeDdRz%2BhzKNdJx6hPr%2BGXOCeAvkBGJpFK0onJh8SJ1p13Kr01vbjFhd5c22W3LsndzkyC7hYuUHJ41%2BprQFsx0aoeIfqsYIT4bKWQ6sCTWRYX3qV63STiAZ5mKXYfNzzB%2B%2B6zksae7nSp%2B82JyQr5%2FU4%2BDXVZepGsijXf%2FPAnXC8tjYYR1FXf2kLHqkVA%2B360RKoPx6kZSQ82G8A%2BA39pRfoJFzA9iZJI9QmgxWxYmXXGP66MBdiyVn0V6wSIOM2nAPZUJoBxDXrK3JOUHjDbJLFdSADjiRDZX2mONbmc3wdYnrARwM72SSrnafjBOI9xpZuzzBgwmjg8TucJ00mi3PRnwIzEMmAxi5jYwW6QOQBgxgJsLfmsMQZyV8iCbuaUMgVMYqhvnVNWSAWBH%2BwPMKx%2FY4yxDn7XwzyuYT8bMN5pWOtz9rXhAGYGAIw0UbMtZCQy32W2hjrPHjAQYx7eJWqOsIDLFTDZKTuJzf%2Fd4l9Qv32mgNnMU80NoaYlC8DOo0m27zIJjn%2BmY5AWMLlLuUH5K1eCC1gTmdkZDYl4h2UIGOe5Bu9Kd%2B0CXChjwJwvwD%2FpgAKYTRF6N5jUEXQw1FxwgZkAJpn4UsgebmXKy7MFjH1R%2F4ncIUdzEzDuRH1NBiZxNDjsAxipXUAVvWQGmIow4Yz2fakHO%2FuSNWCafeDJsQALpzm%2BdWqKaCoyBEzvsALWOZtjtOz%2BN33emVBFOoBxLds6DlRjZoAJ%2BQNGivOUZAqYuP8uRXTddOjSAbabD2Cb00b7HOG1eXJUiXRfeXk6C0xSETSjVE6WgBnGJKwTN3cOzZIqRtJoedYiL7C9R6abBDBSsZ4C5gelbiDAajgFYbanuIktwJrBNg3nSU4D2DkuYOKwHUWLhMdaZ7O%2FL3OYaPwQhQJv0MtTvDFP4qev%2FTw%2FIm%2Ft3o3l4vyOpopKE9P5HmMje968%2B2QXvujERm2Wc3CgZbs9AmE5POPAUxnn6UmTeO0L3iVWMBpjpl9ivCrdaIyB8FjiJH5%2F4053Ngj5O44rrJ9X5kBmQz6LZ%2BjSeP5ByAFsCOcoluIO55vaMLFYP3OukHtc3vs53rOJSUPt%2FASvjPJYcJlVHpXONGgGQmKkFG2uZDhGEyDXTDrvGWm1jXXaIk5YMEKi%2FxapK5Ls%2Bma0BHSKaELtDaBjKYiO%2BfbQtqjKyF2Rx3dInR8vypNq9ZlvAL0odThri%2Fv8V6Qb480jie8JfI%2F5DymggAL6A7%2FPpMSyS0OKAAAAAElFTkSuQmCC)|
|**Programming Language**| ![C Code](https://img.shields.io/badge/C%20Language-informational?style=flat&logo=C&color=003B57)<br>![Python](https://img.shields.io/badge/Python%203.8-informational?style=flat&logo=Python&color=3670A0&logoColor=ffdd54)
|**Integrated Development Environment**|![Code Composer Studio](https://img.shields.io/static/v1?label=&message=Code+Composer+Studio&style=flat&color=black&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACMAAAAjCAMAAAApB0NrAAAACXBIWXMAAA7zAAAO8wEcU5k6AAADAFBMVEVHcEzLAAHMAAHMAAHLAAHMAADMAAHLAAHMAADLAADMAADMAAHJBAXGDQ7LAAHMAADMAADLAAHBCw3LAADLAADBBQbMAQHPAADWAADLAADJDAvBBgbBCwzICwzKDAzKCgvLBAXHCQjLBATVAAC3NTbLAwXEERHKBAbLAADCEhPJBgfLAADJDQzLBgfJDQ3KBQfLAQLHCgvKAwXKCgq2Hx7KCAnLBATHCgrIDAyh%2F%2FjGExLAHyDLBgfLCAfLAgTLAQLLAgSf2%2BfJBgfIDQ7KBgfKBgfKBQbMAgPJBgfICgrLBAXKAwPLCAnJBgfKBQbLAwTLBQbKBAXHCQrJBgfKCgvJBwnCFxrEERHCGBrJBgfLAwPKCwy%2FISbLAgPEDQ3JCAjKBAXLAwXHCgrLAwPGCwrKAwTICwvKCgvGExTBBQbHDg%2FKAgPHCQrBCwzHCgt7t9jCISTKAwPHCQvJBwjIExSj0cHFDg%2FLAwTKBgbMCQnMBwjKBgbGAADGAADLCAnIDAzDAADJBgbHCgvKDg%2FIEhLFFRXLAgPKAwQA%2F6LJBwfJBgjFDw3LCQvDEhPJBQbGEhPLCQq6JibGFBbKAgPIDQ7JExPJBgfABgfKAwTLCQq%2FHyLHCwq9Cw7IBwihTUzFCgvLAADICArGCwvIDQ7KAgPKAwTEEBTCBAjKCAnBBAXCBAXJBwjKAwXJBAXJBwfFCwvGEBDIBgW6QlTHCgzHFhfJCAjGBwjIBwfKAwSoZXXLAwTMAAHMAAG9DxLKCQrICAjLAADCCwzBCwzBCw3LAwTICAnLAwPIDAvFCgnJCgvHCQrICAvJBQfLBAXYAAHMAADWAAHMAAHZAAHXAAHVAAHTAADUAAHPAADSAADWAALWAgPVAADXAALaAAHUAQLWAQPQAQLWAADVAQLLAAHQAADRAADPAQLYAALUAADNAADNAAHSAAHLAQPZAALaAALTAQPLAADMAQLOAAHOAADmAAHaAADRAQLZAADgAQLdAQPiAQLOAgLXAADcAADSAQLTAwVISLWdAAAAznRSTlMA%2B%2Fr7%2FPv%2B%2Fv77%2FfwDAf38%2Bvpe%2FvyQAwMB%2FWGPXQJjjskC0wIH0yC%2B%2BgaZAmKsY6%2F5N8aNCYzBY0sCJxHOzOj99gGVRIvHpuyfgrLcnJ6i5eG5SYaPexAiFpDgkAr8M3G4xFbxP8tFlCuOT%2F1aXFcBD9txc1gDO%2BbDyNbIBwTKVAW%2BUGEwHf7yAXebPqkhtC%2BYEBnuXC%2B3k9mPDGw0fgYs92Q8I%2FPiGZVdjYpu1uB0SjSgAzUTaz5k0ALX9vkmimD4WVtg81PMX0dlU2KJ3d1J1TAAAAOSSURBVDjLddQHfBNVGADw70buvbtrL4mJhajUWgsthdpSbQFBNgIyFQXBKiAyBMS9By7cdU%2BW4N574N5b73K5y2rSmKR7MkXcfpeUtLV4v9%2F9fve%2B%2B79x333vAfS8snMAbgPIGQD%2Fdw1AMer2%2FAXVAEMOro7qB7B%2B7hjVr46bejNA%2F6y%2B4miA4yfc2lQvOopa1FtKLsNYTi%2BR1R%2FgrFllvt2sk%2FpbnU5dbTz5FCvevQ68zyltV1tEjqp%2FDCzrbLGJ1Luj%2FOzxGYVjrCrcZ9RxRIrE754I98x0GpRwvJnM37YlTYbAqjkdftFGNaVh8XyrDfcVBz2E8kX1nUs3Wu1sgJULZntDDE%2BkPY8uuh97bXiuvJUShQsaS2c9kRIfvQbw1ivTwwGZl0K1D0xauejl2giVufqOKRVPAgzahL2%2B%2BOf1NwGq3t2eND2sM9jUHm1jWDGkPr35GYD5c1c%2Fi%2BYzI9Fe%2Bg7Ae2uX%2FO0VWFETnXIg%2Bv6L8wAeL37K%2B9cLaD43P9WNdDpeXdxoaGVSIrnsk8EAw05kOnZvNZ7HF%2Bd57YQREv7yNW9gmkpWd8Yrv8fw8pN2qTpDRDVt8LNdomImX3p7A6b7x28x%2BFVlPCqIVKOMei42j%2FDaiE4EIrv9TQtPOx0jBT98HTM9DBEEXRDVw7uMoLndmDSxIfrlGhj2Uzjgdgs73eJOnXYbTYiZMkc06YP9K%2BC73z6UiS5zoeguqmcM3zz6krwdYc2ls%2BrH8E3MTjSXP7rwppI%2FuW4TmQwwonAsFRy1FXDYz3aBtA4cXgXFv7Bpc4hlrr4Un%2B4yGEftsZbh264aifUw81cc59Au05w3EgbDvWrGBK6Da6%2BHqT1N5ApAM8MyR6bNCZB1DUyw5uoySvDyifiEhvVlDNb3Mr%2BcMboUjBfeCCt8KTO0xi6bV%2BLvGtug6EzaBBxU93jMcOXoNsnhOxWNTWmYU9qo6pJGixIp8%2FseTqpz8XwkJGksmmNqbJoQTFCG6gpH9j6CZt60MWrIxlMXr2iE9Z0BuTWYeIpZV8SgOu6O6lTVj7r4QqxUWdBIxhChTmLqfVMmVafq2dqOBcPzw8122VVnrRnnwv9rCzXNtqqgX3b6tMCNdv7avJhXYljMIRqe9xvTL7oA%2B2f32Mx4j7hhn%2BEMV8DQGGsmt%2BcW9BYH1J2lZ%2B59DHL3x5esG99XHDgYHnp4Gjw4eXmv46DvAVMFx%2F1X%2FAuakVjhU6Z2TQAAAABJRU5ErkJggg%3D%3D&logoHeight=40) |
|**Operating System**|![FreeRTOS](https://img.shields.io/static/v1?label=OS&message=FreeRTOS&color=white&labelColor=green&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAMAAABg3Am1AAABLFBMVEUAAAA3Nzc4ODg6Ojo7OzsRERESEhITExMgICBFRUVHR0cMDAwNDQ0ODg4LCwsPDw8ZGRkUFBQVFRUJCQkKCgoLCwsUFBQNDQ0TExMKCgoICAgKCgoICAgKCgoLCwsGBgYGBgYHBwcICAgICAgJCQkICAgFBQUHBwcFBQUHBwcFBQUGBgYFBQUEBAQEBAQEBAQDAwMDAwMEBAQDAwMDAwMDAwMDAwMCAgIDAwMCAgIDAwMCAgICAgICAgIDAwMCAgIDAwMCAgICAgIDAwMCAgICAgIBAQEBAQECAgIBAQEBAQECAgIBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEAAAABAQEAAAAAAAABAQEAAAAAAAAAAAABAQEAAAAAAAAAAAAAAADpWFtfAAAAY3RSTlMAAgICAgQEBAQEBAgICAoKCgwMDg4ODhAQFBYWGBgYGhwcHiAgIiYmKCosMDg8QkRKTExSVFZcXl5gYGJmampubnR4en6PlZeXnaWlra%2Bztbe7vcHDz9Pb293f4fHz9fX3%2Bf1wHG5lAAACEklEQVR42pXWhWKjWhgE4Km7u7u7u7u3cSU08%2F7PcO%2Fuz8HJEr5KdHDmHPjMHj%2FG8yWylI8%2FHs8ixOhNki7Jm1FUNv2sk9rX7fbScEvr8NL27ZdG6k8zCNZ%2Br5Pf%2B11w6Nr7JvX7dgRYTZHvqwHvv5OpgPf3NWY3EWgzS20fHtfkWz8q6Hsjr33fv6tBRfV3nsQ%2BeYl%2FuiT3Hful8Q4h7qgZe06iPcW3OjgN6CTdZ7n%2Bjal2Fbhntg8uxyR5A5f%2BLO%2BNwIzOTZgm%2Fv5rTJJkrlO9oWxSn5HAE99h2v2N7QyufFD8rPVufZYPYXrnkwR0rtrfp4%2BdWKU%2BCpD8hjKkM0B5Dso3bwAqaqUBEjDtMekJbDDAnn3tapyFS3OZfhOwfPEYLgs06C9nR49FGtZhueUjnBreKdKLcv8lKWJtMG0zDtvIeYridxliqkCRuRqHYYl52ApUXqE8UCn3QAyzBJtG5QLKAU2DEK0kyNaqA6LE4ao3SeS5VPVOizi3qz6s4pG3gSfuxH%2FiDMf8Crk0xuAyS03KMeziowIkjXfCLm87cBN6A81D%2BZbAaJRblATgKYHtnpV3itha96a7BJ4l4KqZyb%2F%2FmirVzLQE%2FhZZf3iR9f0tMglIVdaHVWWdVCUZuYyj1709oNSjolpjQIk%2BZEUfFKMPu%2F6BfS9oYO9AsJkna%2BrQ2hI%2BdYg%2BOfFPf05n4fU%2FmeU4udThUscAAAAASUVORK5CYII%3D)|
| **Electronic Design Automation** | ![EagleCAD](https://img.shields.io/static/v1?label=&message=EagleCAD&color=E3D8CD&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADEAAAAxCAYAAABznEEcAAAAAXNSR0IArs4c6QAACUdJREFUaEPtWX1sVtUZ%2F52P%2B75vW6At31hMgbasAxS1DIMTkLEghk0Ss8WvmLGFZUsW56a4qRvsw5DsDzKSZXER4zY0m9PuIxFmRAvWAYM6aKG10oI2tJShFKl2bWnfe%2B95luec21q3xPaUjxDiTd68995z7rnP73l%2Bz3k%2BrsAVcIgrAAM%2BBXG5WNHbEo%2FdUTGtK8zmTxkbbJwyRsyRQkzNz5EFeQFBCgEtHTQlCBASqRQhoBjSROjopf%2B0nJV7PuiLHvnRc2%2FWXygleIHY%2BbNl1HHyBCiMEGZD6DH5qFhUgcZDDXj%2F5Cnk5qYtEKUUlIgRBBopCUjJ4PhHkIgRSEArCZ2ThyB3HHIKx%2BMHr76oKysRjwaYF4ita2ZTYR6ht7sXRISY3OPGRCDSIBhksyFKrpmHWTOLcPj1amgloISCVgSlgICFF4AQAilFCIIUVEpDp9MQOoOyh%2Fd5ycTv93rg6XuKyUQRCvIAYgBEFoyxQARi4jM3xjoPTcwDgE7j9jtWoK5qB9IpibRi6jEwQAsByf%2FWYhKZlMKM9c1ecnlNfuruq4mFGlcwDqmwGzE54xtjHBghYCBAxoEjkogZl4gQG%2BmsFxuUziunTFer0CIBJAElhf0JKVH%2B82NecnlN%2Fu1dVxHLzcotzBNIaZEICyssa9%2BQsSBYdqabA8MgJQx4zIFx82Lc%2BtXVOHvgFSgdWGuwv5Q93uIll9fkrfdMo4icENmYUDxeJ5ZIaEXS8jNkQAnVBulmBR8AxRZjEO46NgI3LlkAdarRWmND8w26srJyxE7uB%2BLeIrJ8F8KaY%2BJYgmZvJSQ0Yo3bS%2Bsjhu%2Fztd0EHPeYbkyp5BKGwRknRmQMFs5MY1vLmNXrKxtfHOlO5QXi2fuKyLAlmPMAppeVQXS8M7gvOq0OWIHBCBh2HMFOz9ZKND9kQ%2BB7zqcYNFsIKJ2a07l089vjLwqIP95XxGErEc7AmBAzJqUthVibFoTdnVjgj6zgzt09Oz7oF04ZrJSIV7FWA9LI4s4%2FdIxYwSOeyFp57mtFxNplDtutFAKlMyYg7jqbUId57%2FwCJgSpFI52it8QqX4tkTEmRhhGORAyHcWxFFIrAxOK2PRFqdyTO46GW6oOtrSN1AID87xAPL9mOhm2RKIx1u6CJZ9H51v77XbLGuUjNITlv27zWttX8KHzvV70569fbS0RJc7KPO7v78Pc6XkJMAdi0ebjXuueDwDviP3Xb0wnIxQ4EMdw26oQBmWTUm7nYR82ET73yxOXL4i%2FrS22iYWjE7l9HkDZBEAoDmaOUgs2XcaW2P7NIopFKnFit9cbQygtCKEzOWwbwEhUncq%2F66Fnap8%2FX5qM9Hkvs2%2F71iyykdbu90wfB2TBdbPQfarVphdu15Loj0T01K6C3C0HD4YjFWa087xAvPTtWezXVvvsExwbBBFuXnkLOg7tdgCSAOF8xlVIfC5sUIuRkoQsNDq6TUsW%2Br3T51JNu1vMM7%2Bvbqq%2BJCB2fKeUXNByeZC1BAgrbl%2BJEzVVNqA5IAmYxNntfR4SnChKmLAflDcBYWYMorAfSqfx9%2Frer2x8oe4vowHiZYlX7y8hzmC57ORUwabi1hJfxJnaXYnWk0BoiedQcA1SOO9mvHHwTWQCtwlwBsx5l1ICgZaobw8fXPtE7eaLDmLnd0vJWcFpO4ltqFj4WXS1NH3s%2FZxGTL1%2BCV7eVgWdl4eAKzwloLWy51yyKq7ytLSlak1rdu39T9Y9fdFBVH%2BvjOIk%2BWO%2FsLkQScyeqoAoGny%2FLpyMfUc6oLSCVDIBwJWbQkopCOWKIAYkud7WCgsf3e%2FFilFH7Ne%2FP9v6hAWQ5E7Mr%2BKxWaggbe9k5i3Hntf%2B4TQNQLL2FYOB07yQUNqdczkaBBLpIJW97uHdvMCoDi%2F0ux%2F6zCCdLJU4hQZQXMC5qcLEG2%2FDKy9VuY4HNwMk00ZBSWOtwgAcGL7PYNL48FxUf9vGmvmjkj55yAvEnnXlJMg59IA%2FZLMRZk5UMFEfGrrGQvF2KhVX2tYaQnHZGSdgnC%2BkA4H9x%2BWaB3%2F3xtbzEX7gWS8Qe9fNIc6VmE5MHf7jUnTmuAinC%2BbivbYWCN5HBbC9Ibp2S1VTw4UQcrg1vED8c91cgnABmINzDIE5i5eh40AVjnVr6CBlY8iqTQ1e6w4n5HDjXi9jS2gVD9bNvHjhxELEH55Ge5xvrcOl6MpfHPJadzghhxv3elnND8sJxEkEl6iu6B8jzoELvbNyvKUR%2B8IXNl7GIOoe4bRDgiMCJ1F9%2FVnkau7mSXTKXKQzaRgjccvj%2F%2FJSznCaHm7c62WHHy0j2xBLcqKr5i9E24G9NnzPW3YrDtfVMpvQ3iX%2FdOemmruHe%2FmFGvcC0fhYCUXc1056St09vXbrtIcAgkmT7f7Pi57LijNLf7p%2F0oUS9JPW8QPx4zKbpkYGCLP96OrjVJtLVNu0wZTZc9Hd%2FQGk9Q1OKThmcLoB8Ewb%2FIRAXxadsZBtnIL19FGvAnryx6rJPGYImWsf2FXuA94LRPNPyshEBrGQmFB%2BPQ7v3ZcAcK%2B07chVX0b70Tp7zYGNt1wWjhvFNhWxbX3Ye5KzWBvVXaufx2UUY8ranV5yeU1u3lBC0tqC0Pxu1u1G1goJo3hMEhZ%2FaTVa36m3FhngGn9kGRCen2FQioElrf0BIO31R1Cxya%2Fd4wXi7Q0zCNAgrdHY2mM7HYxEKAWKIyuQgwjcsGw5es602CzWajkZsxbh3Iq1wbkUg7GZooQig2O1zd4tHy8Qx9YXkxAB6tqzrr%2FPEAYtwUIxAta47fMjzvajYukiaJxLaMUpOE9x1LKWSf55Lf5M1ri%2FEUt%2B1eoll9fk5vUlpCnmAmbwGxMvMACE6%2B2PA0vIpBUWL70GcRgOOrqlFH%2BcHPKxShqgtqYJK564yCDaezM4%2Be7ZhOu8M7m2po3fTJuhX9BY1TYT4XlASDFuWnwT8oNu%2B33LNhWG%2BFR3RxeONJ%2FAqifbvZTrNbllfTG9drTf%2BcFQh%2BZzwTWFzWGTsDFw5gD878FFEWNYuGg%2BCsc532pqaMOzjVS8ZftbXk1lLxAvPzCXjv%2F7fadBpSEMN%2FrdYbiGIOZ40tmwHu78xFmI%2FZi%2FDhkbIMlEyNNAfc%2F4F%2FZ0Tru3urr6o%2Fr2%2FzF%2F4h0vEJ5rX7Lpn4K4ZKoe5kVXhCX%2BC1G0f24AESeRAAAAAElFTkSuQmCC)|




<!--- ![FreeRTOS](https://img.shields.io/static/v1?label=&message=Operating+System&labelColor=white&logoHeight=40&logoWidth=50&color=white&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGMAAAAmCAIAAABfzLIdAAAKgklEQVR42u2aBVRcOxPHee7u7u7%2BWqzu7u7u7u4GNZy6UeVRd1rcXWpI3Ys7VH4f817ellvuYdnPy5ycPXeTySb5Z%2FKfyew1u3235BflXUo%2FnXQ99j4ucVcyzhUW5ZdA5m%2Bk0nKubw5fPH5nyyHbaleUSbvbbo92ycpPL4kUQNJWQruizNjX5WJ68t9IXc%2B6NHFXGxpGejT0iHJOvh6XnnsjOz%2Fj%2FixpOdcSrkVzvIa71wOT6fu6ZOal%2FonU6qBZVI3yaIxlKWOrkLhLQcP%2FqA8y7pEOfDXLyEsZ8UcDvh887qaUCgsLHdbbpKSk8Hzz5s209DSpz8jMsF05jc%2F7BCz3KEeQGbezRX5hrhnI8WWoe92U7CtKIz09vc1M85iYaJ4DgwPaTagu9YmJCe3nmfP5X7KSW7du3fxLeP6n9z2XekoI62zKCbOA5L0CW0FR3j2R8vI90mGWtRYpLG7YsGEd75a%2BffuOGzdu06ZNV69eZQYlBp41a1anTp06llnWr1%2BPdWsXcOLEiWnTptWoUeP9999%2FuVg%2B%2FvjjBg0a2NjYnDt3TsYtTWg9dOhQt27dvv7661dfffXNN9%2F85ZdfhgwZ4uvrqx0L2hrmXhd84i8Hm%2Fkm7uRpwq7WBUX5JZCKio7id496e4KUYH8q4aRCavny5Waly9NPPz1w4EDwUtvFPJ5%2F%2FnkzY6Ry5cpXrlwxnPrly5d79%2B796KOPltblmWeemTBhAvO%2Fp5lcv369fv36DzzwgLYjlS1atKCjoX5uQbZQFSevVKQ6LrDsY9N40NJWvW0a9nKtxgOlr22TrvbWgpS9vb2M8dRTT73xl7z00ksPP%2FywGv7333%2B%2FePGiTBqgLSwsnrtbWJhoPvjgg88%2B%2B2yJ1latWl24cEHN6tSpU9iO%2BnHG%2BvXXX7EsS0vLTz75xHDcOnXqqHGVFBQUVK1aVRQeeeSRH374oVGjRg0bNvzqq6%2F4KmCFhYUxTyOQQtvRbcEStxnaYu82LzcvFx07OzsZlfGCg4OPFUtsbOzevXu7dOny0EMPSSuWlZOTI7yQmpoaHx8fbSAHDx4UNVDmUERFRRm2njx5kr7KHD788ENRBtOhQ4d6eXmhcP78eUA5ffr0%2Fv37sRcQF522bduWMBDOsjS9%2BOKLS5Ys4ffZBmz27Nmz9G3WrBk%2F6%2B%2FvX1RUVHakyiQKqebNmzOeYkdGysjI6Nmzp7S%2B9tprZ86cASZFooZCk6jBF4DICS2hoIbr2rWrMiUOPtDk5eXdMhDGZScGDRokamzVhg0bDKmnSZMm0gSZJicnqybpm5aWFh4eDnZ8NQKp%2FPz8GY6jL1%2B5LPySmJQo9SmpKeMXD4DLDZHieMNHJXBkVHUWjh49KhulFfZTIYVJqllqKVy4CZPBLejQdlZW1k8%2F%2FSS%2FWa1aNSxRwfH9999LvZOTU3Z29j3JHjGap5Tv8%2Fb1ajPZUuv79JG6ceOGHH5k586dcIQpSOFPRY3VRkZGsnk6vn%2Fz5s2KjEJDQ2Xx1CsEZ8%2BenZsLgeiL8UhJlGAkUmgmiouBaL29vVlbuZFiqT%2F%2F%2FLOoEZdcu3ZNf3mcoxdeeEH0nZ2dOR%2BCVPv27aXyyy%2B%2FVITwn0dq4sSJ0vrNN9%2FExcWx2nIjBfuIiwT6jRs36puDcrLys9BWZmam1GPaKj4ghoqIiBBOMBWpTjZW7WdbdZxj3WGuVZ9V1XigUNPN0RraKoGUYdTDShYsWCA%2Bm8%2F58%2BeLFZQbKfyp6Dz22GOBgYHKPHUOYOfOnaVL69at4QFFvoQdij2ffPLJXr16HT9%2BHGTLjxSyadeaNR7O2uK2Y5XMVSH1zjvvNG7cmEkg1atXxwdL%2FRNPPDFy5EimwtaZgpSPj4%2FyejExMbIwfSGGkC716tUz3EVQY5ISSSgu69ChA1avnaSpUYIyfoWUVphK7dq1165dm5CQIDRhClK7d%2B9WMZfS0ZcxY8ZIl5o1a166dMnQ3IhgXFxcPvvsM1FQmzpixAiOOQpGI8XWefkfXr9jeUhEoNScOHXMYdPc7nPqljh90OfnxcJKhAj4JDrn1Ij1mYiUik6534lO2W0KYzdESh1DxoUioHaZsIIVojAunkLW73Lpu7p6u3mVucrsPLRt3tpxvV2r91hUa%2FH66bm5OYKUmg3siLNjGW5ublw4VDiDtZuOVFBQkLo2gX5ZTh%2F3cOmCv9N6GzEuAlfiewcHB9hDgdW%2Ff39uBUYgxQ91n1%2FHZfMiztoad5fOi60Guzb12L%2BJuE4UtIwugTJGBJVwRxfLsrW1Nf30JSUlCbPw6enpqcN6avJYtPzs2LFjCRp0NJke18lKlSopmueqwGaUFSkOc7s55uHhYTwDfJcl1t7%2BRwzH0IkSGIbshzR9%2BumndGdCpiBFPE2rqHFf04de0kFkMkR%2F3bp1YiP6yGKqUJV0WbFiBUMYESW0nWW%2BesNyL7%2FDO%2Fa6t59rsW7TKp4pPgFe7KoOUhIBwSlqYAnQTYk88Q%2Bixj1WbERHQEddOTm5wpX6worIKEgvwhrALStSqLaeZt7FzrKLnQWlu7M1n1LazK6UkHBKHykWPHjwYGklbmCTTUFKcmGKqshb6FAVu0KKTpTbtWtXxlgcNKFXdSs0AinkwsUL%2BDhtSUpOYuyy3JC5zUvAEhAQYEqMjuCScKyiSfwttHhP0%2BjTp4%2Bokd7aunWrIlZ8C1ma0qybgFZmyxk8fPiwEaePeQSHB6oO3Mi1M9NHijmZm5uLwoABA%2BAaU5ACaMxKefTffvsNy8IQlD4POF%2B8sEpgEijgCtQOrVq1ikoSWCQ2cFOGHdlUEoHSsW7duuQtjGP01tMrR0SEy5qbjalEptgopJgBt1NRePvtt8kHUVNupCTiJSmowOKeRG6AaGD48OHkm6ysrDAHFfeSg2f9xAHaNB6t%2BBk64haJNiEHlWtmnh4eHqzduHsfLM5gPDNe25nmpC%2BMQgqhUm42LM%2FV1RXETUEK4a47c%2BZM%2BU2tKBYfPXo08Z3iGuVkatWqpYDWCoyOKyBM1Yk8d5UPKZK5cCdEOH78eFjgnkeGTBAbiG0TNwhlaD06vPPRRx9xLrj66CMllkVWF1sgGcD%2FFw8VC%2FbFlZAjyV8sBPSgr40kJDdN6op73wcffMBlWzqCO8HU5MmTyQtDMnqZvLCzR4r%2FZ2%2BUW5htiFRHG6t%2BC5qPsO84zK5DT9eqfef%2F45kybFEnCFXokx0gbCNiKo0pQRnvw8kn6yreWrsAwAIjOEULZWmcBesxNHdvfAU8zSfpPWaCFQsH6fg4ggymhD5ZM9DB%2BuiIxwBcbUf%2BeQccysmrEWZnU07KlxNXIgydiO2qqfPXjteWuSvG3Ui5odaJ6MzMKJ1y%2FC3KPFk8nwhfjfpPVPrqdww76wky%2FOV3I%2FuyWdHNQt7o4PtSrxE8K6UKyS%2FKnXuwN8jYeg4CWzOqApP3iVmtCJiWkZtCTYVgRA4%2Bo4vfQ6gTezHgz3ddAGxDqI2ANcqjkaPPWLcw203hi%2B%2FP4hZqY%2Bc9St5qGbqtzo6YZXe9aVZ0q2hv%2FFpeDKJZSkUZu6PZ0VPumJFC6i6T8zyxZVXgTDvvkUu8ht%2BfBYPihTLvBA9et9O851kGqZA7hD1hk6I9Qm8AAAAASUVORK5CYII%3D) -->

## **IPIA License and Release**

| **License** | **Latest Release**|
| :---:   | :---: |
|[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) | [![Release](https://img.shields.io/github/v/release/jminjares4/IPIA_FREERTOS?include_releases)](https://github.com/jminjares4/IPIA_FREERTOS)    |


## **Acknowledgements**
- **Dr. Hector Erives** :zap:
  - Senior project I & II Sponsor
- ECE Department (UTEP) :zap:

## **Authors:**
* [**Jesus Minjares**](https://github.com/jminjares4)<br>
  * **Bachelor of Science in Electrical Engineering**<br>
[![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:jminjares4@miners.utep.edu) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jesus-minjares-157a21195/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/jminjares4)
* [**Erick Baca**](https://github.com/eabaca2419)
  * **Bachelor of Science in Electrical Engineering** <br>
    [![Outlook](https://img.shields.io/badge/Microsoft_Outlook-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white&style=flat)](mailto:eabaca@miners.utep.edu) [![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/erick-baca-484bbb215/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/eabaca2419)



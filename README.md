# Arduino Environment Monitor 🌡️💡

Un sistem de monitorizare a mediului în timp real, bazat pe platforma **Arduino**, care măsoară temperatura și intensitatea luminii folosind senzori analogici și prelucrare digitală a semnalului.

## ✨ Caracteristici
* **Monitorizare Temperatură:** Conversie precisă din voltaj în grade Celsius pentru senzori de tip TMP36.
* **Filtrare Digitală (Averaging):** Implementează o funcție de mediere a 10 eșantioane consecutive pentru a elimina zgomotul de citire și a oferi date stabile.
* **Analiză Luminozitate:** Clasificare inteligentă a nivelului de lumină în trei praguri calibrate: **ÎNTUNERIC**, **NORMAL** și **LUMINAT**.
* **Interfață Serial:** Output formatat și ușor de citit direct în Serial Monitor (9600 baud).

## 🛠️ Detalii Tehnice & Calibrare
Proiectul utilizează un ADC (Analog-to-Digital Converter) de 10 biți pentru a interpreta semnalele:
* **Rezoluție ADC:** 0.0049V (5V / 1023).
* **Sensibilitate Temperatură:** 10mV per grad Celsius.
* **Praguri Lumină (Valori Analogice):**
    * `< 20`: Întuneric (senzor acoperit)
    * `20 - 80`: Lumină ambientală normală
    * `> 80`: Lumină puternică (lanternă/soare direct)

## 🔧 Schema de Conectare
| Componentă | Pin Arduino |
| :--- | :--- |
| **Senzor Temperatură** | Pin Analog **A0** |
| **Senzor Lumină (LDR)** | Pin Analog **A1** |

## 🚀 Instalare și Utilizare
1. Clonează repository-ul sau descarcă fișierul `.ino`.
2. Deschide proiectul în **Arduino IDE**.
3. Conectează placa Arduino la PC.
4. Selectează portul corect și apasă **Upload**.
5. Deschide **Serial Monitor** (Ctrl+Shift+M) setat la **9600 baud**.

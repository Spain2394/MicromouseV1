<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="STM32F030K6T6">
<packages>
<package name="QFP80P900X900X160-32N">
<text x="-5.274540625" y="-5.92546875" size="1.273240625" layer="27" align="top-left">&gt;VALUE</text>
<text x="-5.36946875" y="5.619840625" size="1.272190625" layer="25">&gt;NAME</text>
<circle x="-5.74" y="2.77" radius="0.1" width="0.2" layer="21"/>
<circle x="-3" y="2.77" radius="0.1" width="0.2" layer="51"/>
<wire x1="3.6" y1="-3.6" x2="-3.6" y2="-3.6" width="0.127" layer="51"/>
<wire x1="3.6" y1="3.6" x2="-3.6" y2="3.6" width="0.127" layer="51"/>
<wire x1="3.6" y1="-3.6" x2="3.6" y2="3.6" width="0.127" layer="51"/>
<wire x1="-3.6" y1="-3.6" x2="-3.6" y2="3.6" width="0.127" layer="51"/>
<wire x1="-5.21" y1="-5.21" x2="5.21" y2="-5.21" width="0.05" layer="39"/>
<wire x1="-5.21" y1="5.21" x2="5.21" y2="5.21" width="0.05" layer="39"/>
<wire x1="-5.21" y1="-5.21" x2="-5.21" y2="5.21" width="0.05" layer="39"/>
<wire x1="5.21" y1="-5.21" x2="5.21" y2="5.21" width="0.05" layer="39"/>
<wire x1="-3.3" y1="3.6" x2="-3.6" y2="3.6" width="0.127" layer="21"/>
<wire x1="-3.6" y1="3.6" x2="-3.6" y2="3.3" width="0.127" layer="21"/>
<wire x1="3.6" y1="3.6" x2="3.6" y2="3.3" width="0.127" layer="21"/>
<wire x1="3.6" y1="3.6" x2="3.3" y2="3.6" width="0.127" layer="21"/>
<wire x1="3.6" y1="-3.6" x2="3.3" y2="-3.6" width="0.127" layer="21"/>
<wire x1="3.6" y1="-3.3" x2="3.6" y2="-3.6" width="0.127" layer="21"/>
<wire x1="-3.6" y1="-3.3" x2="-3.6" y2="-3.6" width="0.127" layer="21"/>
<wire x1="-3.3" y1="-3.6" x2="-3.6" y2="-3.6" width="0.127" layer="21"/>
<smd name="9" x="-2.8" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="10" x="-2" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="11" x="-1.2" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="12" x="-0.4" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="13" x="0.4" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="14" x="1.2" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="15" x="2" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="16" x="2.8" y="-4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="25" x="2.8" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="26" x="2" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="27" x="1.2" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="28" x="0.4" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="29" x="-0.4" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="30" x="-1.2" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="31" x="-2" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="32" x="-2.8" y="4.18" dx="1.56" dy="0.55" layer="1" roundness="25" rot="R90"/>
<smd name="1" x="-4.18" y="2.8" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="2" x="-4.18" y="2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="3" x="-4.18" y="1.2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="4" x="-4.18" y="0.4" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="5" x="-4.18" y="-0.4" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="6" x="-4.18" y="-1.2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="7" x="-4.18" y="-2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="8" x="-4.18" y="-2.8" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="17" x="4.18" y="-2.8" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="18" x="4.18" y="-2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="19" x="4.18" y="-1.2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="20" x="4.18" y="-0.4" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="21" x="4.18" y="0.4" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="22" x="4.18" y="1.2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="23" x="4.18" y="2" dx="1.56" dy="0.55" layer="1" roundness="25"/>
<smd name="24" x="4.18" y="2.8" dx="1.56" dy="0.55" layer="1" roundness="25"/>
</package>
</packages>
<symbols>
<symbol name="STM32F030K6T6">
<wire x1="-25.4" y1="27.94" x2="25.4" y2="27.94" width="0.41" layer="94"/>
<wire x1="25.4" y1="27.94" x2="25.4" y2="-30.48" width="0.41" layer="94"/>
<wire x1="25.4" y1="-30.48" x2="-25.4" y2="-30.48" width="0.41" layer="94"/>
<wire x1="-25.4" y1="-30.48" x2="-25.4" y2="27.94" width="0.41" layer="94"/>
<text x="-25.4275" y="28.9707" size="2.085009375" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-25.4512" y="-34.5348" size="2.08635" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
<pin name="PA14/SWCLK" x="-30.48" y="-22.86" length="middle" function="clk"/>
<pin name="BOOT0" x="-30.48" y="22.86" length="middle" direction="in"/>
<pin name="NRST" x="-30.48" y="17.78" length="middle"/>
<pin name="PA0" x="-30.48" y="12.7" length="middle"/>
<pin name="PA1" x="-30.48" y="10.16" length="middle"/>
<pin name="PA10" x="-30.48" y="-12.7" length="middle"/>
<pin name="PA11" x="-30.48" y="-15.24" length="middle"/>
<pin name="PA12" x="-30.48" y="-17.78" length="middle"/>
<pin name="PA13/SWDIO" x="-30.48" y="-20.32" length="middle"/>
<pin name="PA15" x="-30.48" y="-25.4" length="middle"/>
<pin name="PA2" x="-30.48" y="7.62" length="middle"/>
<pin name="PA3" x="-30.48" y="5.08" length="middle"/>
<pin name="PA4" x="-30.48" y="2.54" length="middle"/>
<pin name="PA5" x="-30.48" y="0" length="middle"/>
<pin name="VDD" x="30.48" y="25.4" length="middle" direction="pwr" rot="R180"/>
<pin name="VDDA" x="30.48" y="22.86" length="middle" direction="pwr" rot="R180"/>
<pin name="VSS" x="30.48" y="-27.94" length="middle" direction="pwr" rot="R180"/>
<pin name="PA6" x="-30.48" y="-2.54" length="middle"/>
<pin name="PA7" x="-30.48" y="-5.08" length="middle"/>
<pin name="PA8" x="-30.48" y="-7.62" length="middle"/>
<pin name="PA9" x="-30.48" y="-10.16" length="middle"/>
<pin name="PB0" x="30.48" y="10.16" length="middle" rot="R180"/>
<pin name="PB1" x="30.48" y="7.62" length="middle" rot="R180"/>
<pin name="PB3" x="30.48" y="5.08" length="middle" rot="R180"/>
<pin name="PB4" x="30.48" y="2.54" length="middle" rot="R180"/>
<pin name="PB5" x="30.48" y="0" length="middle" rot="R180"/>
<pin name="PB6" x="30.48" y="-2.54" length="middle" rot="R180"/>
<pin name="PB7" x="30.48" y="-5.08" length="middle" rot="R180"/>
<pin name="PF1-OSC_OUT/I2C1_SCL" x="30.48" y="-12.7" length="middle" rot="R180"/>
<pin name="PFO-OSC_IN/I2C1_SDA" x="30.48" y="-15.24" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="STM32F030K6T6" prefix="U">
<description>None</description>
<gates>
<gate name="G$1" symbol="STM32F030K6T6" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFP80P900X900X160-32N">
<connects>
<connect gate="G$1" pin="BOOT0" pad="31"/>
<connect gate="G$1" pin="NRST" pad="4"/>
<connect gate="G$1" pin="PA0" pad="6"/>
<connect gate="G$1" pin="PA1" pad="7"/>
<connect gate="G$1" pin="PA10" pad="20"/>
<connect gate="G$1" pin="PA11" pad="21"/>
<connect gate="G$1" pin="PA12" pad="22"/>
<connect gate="G$1" pin="PA13/SWDIO" pad="23"/>
<connect gate="G$1" pin="PA14/SWCLK" pad="24"/>
<connect gate="G$1" pin="PA15" pad="25"/>
<connect gate="G$1" pin="PA2" pad="8"/>
<connect gate="G$1" pin="PA3" pad="9"/>
<connect gate="G$1" pin="PA4" pad="10"/>
<connect gate="G$1" pin="PA5" pad="11"/>
<connect gate="G$1" pin="PA6" pad="12"/>
<connect gate="G$1" pin="PA7" pad="13"/>
<connect gate="G$1" pin="PA8" pad="18"/>
<connect gate="G$1" pin="PA9" pad="19"/>
<connect gate="G$1" pin="PB0" pad="14"/>
<connect gate="G$1" pin="PB1" pad="15"/>
<connect gate="G$1" pin="PB3" pad="26"/>
<connect gate="G$1" pin="PB4" pad="27"/>
<connect gate="G$1" pin="PB5" pad="28"/>
<connect gate="G$1" pin="PB6" pad="29"/>
<connect gate="G$1" pin="PB7" pad="30"/>
<connect gate="G$1" pin="PF1-OSC_OUT/I2C1_SCL" pad="3"/>
<connect gate="G$1" pin="PFO-OSC_IN/I2C1_SDA" pad="2"/>
<connect gate="G$1" pin="VDD" pad="1 17"/>
<connect gate="G$1" pin="VDDA" pad="5"/>
<connect gate="G$1" pin="VSS" pad="16 32"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="Unavailable"/>
<attribute name="DESCRIPTION" value=" MCU 32-Bit STM32F ARM Cortex M0 RISC 32KB Flash 2.5V/3.3V 32-Pin LQFP Tray "/>
<attribute name="MF" value="STMicroelectronics"/>
<attribute name="MP" value="STM32F030K6T6"/>
<attribute name="PACKAGE" value="LQFP-32 STMicroelectronics"/>
<attribute name="PRICE" value="None"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="STM32F030K6T6" deviceset="STM32F030K6T6" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="30.48" y="99.06" size="1.778" layer="91">STM32 Processor</text>
</plain>
<instances>
<instance part="U1" gate="G$1" x="40.64" y="55.88"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>

#if !defined(FLEX11_6_FLASH_PRINTING_PRINTJOB_AS)
#define FLEX11_6_FLASH_PRINTING_PRINTJOB_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace geom
    {
        class Rectangle;
    }
}
namespace flash
{
    namespace display
    {
        class Sprite;
    }
}
namespace flash
{
    namespace printing
    {
        class PrintJobOptions;
    }
}

/**
 * The PrintJob class lets you create content and print it to one or
 * more pages. This class
 * lets you render content that is visible, dynamic or offscreen to the user, prompt users with a
 * single Print dialog box, and print an unscaled document with
 * proportions that map to the proportions of the content. This
 * capability is especially useful for rendering and printing dynamic
 * content, such as database content and dynamic text.
 *
 *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Mobile Browser Support:</b> This class is not supported in mobile browsers.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> This feature is supported
 * on all desktop operating systems, but it is not supported on mobile devices or AIR for TV devices. You can test
 * for support at run time using the <codeph class="+ topic/ph pr-d/codeph ">PrintJob.isSupported</codeph> property. See
 * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
 * AIR Profile Support</xref> for more information regarding API support across multiple profiles.</p><p class="- topic/p ">Use the <codeph class="+ topic/ph pr-d/codeph ">PrintJob()</codeph> constructor to create a print job.</p><p class="- topic/p ">Additionally, with the PrintJob class's properties, you can read your user's
 * printer settings, such as page height, width, and image orientation, and
 * you can configure your document to dynamically format Flash content
 * that is appropriate for the printer settings.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> ActionScript 3.0 does not restrict a PrintJob object
 * to a single frame (as did previous versions of ActionScript). However, since
 * the operating system displays print status information to the user after the
 * user has clicked the OK button in the Print dialog box, you should call
 * <codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">PrintJob.send()</codeph> as soon as
 * possible to send pages to the spooler. A delay reaching the frame containing
 * the <codeph class="+ topic/ph pr-d/codeph ">PrintJob.send()</codeph> call delays the printing process.</p><p class="- topic/p ">Additionally, a 15 second script timeout limit applies to the following intervals:</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">PrintJob.start()</codeph> and the first <codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph></li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph> and the next <codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph></li><li class="- topic/li ">The last <codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">PrintJob.send()</codeph></li></ul><p class="- topic/p ">If any of the above intervals span more than 15 seconds, the next call to
 * <codeph class="+ topic/ph pr-d/codeph ">PrintJob.start()</codeph> on the PrintJob instance returns <codeph class="+ topic/ph pr-d/codeph ">false</codeph>,
 * and the next <codeph class="+ topic/ph pr-d/codeph ">PrintJob.addPage()</codeph> on the PrintJob instance causes
 * the Flash Player or Adobe AIR to throw a runtime exception.</p>
 *
 *   EXAMPLE:
 *
 *   The following example show the basics of printing. A new PrintJob is created,
 * and if started successfully, the <codeph class="+ topic/ph pr-d/codeph ">addPage()</codeph> method adds the sprite as a single page.
 * The <codeph class="+ topic/ph pr-d/codeph ">send()</codeph> method spools the page to the printer.
 *
 *   <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.printing.PrintJob;
 * import flash.display.Sprite;
 *
 *   public class BasicPrintExample extends Sprite
 * {
 * var myPrintJob:PrintJob = new PrintJob();
 * var mySprite:Sprite = new Sprite();
 * mySprite.graphics.beginFill(0x336699);
 * mySprite.graphics.drawCircle(100, 100, 50);
 *
 *   public function BasicPrintExample()
 * {
 * if (myPrintJob.start()) {
 * try {
 * myPrintJob.addPage(mySprite);
 * }
 * catch(e:Error) {
 * // handle error
 * }
 * myPrintJob.send();
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example uses the class <codeph class="+ topic/ph pr-d/codeph ">PrintJobExample</codeph> to create a small document and
 * then send the document to the printer.  This is accomplished using the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Declare two variables of type Sprite named <codeph class="+ topic/ph pr-d/codeph ">sheet1</codeph> and <codeph class="+ topic/ph pr-d/codeph ">sheet2</codeph>.</li><li class="- topic/li ">Call <codeph class="+ topic/ph pr-d/codeph ">init()</codeph>, which assigns a new Sprite instance to both <codeph class="+ topic/ph pr-d/codeph ">sheet1</codeph> and
 * <codeph class="+ topic/ph pr-d/codeph ">sheet2</codeph> and then calls <codeph class="+ topic/ph pr-d/codeph ">createSheet()</codeph> using different arguments.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">createSheet()</codeph> does the following:
 * <ol outputclass="A" class="- topic/ol "><li class="- topic/li ">The Sprite object passed in is used to draw a rectangle with a light-gray background, a
 * one-pixel black border, and that is 100 pixels wide by 200 pixels high at x = 0, y = 0.</li><li class="- topic/li ">A new TextField object is created named <codeph class="+ topic/ph pr-d/codeph ">txt</codeph> with the same dimensions as
 * the Sprite, the wordWrap property set to <codeph class="+ topic/ph pr-d/codeph ">true</codeph>, and the text property set to
 * the String passed as an argument to <codeph class="+ topic/ph pr-d/codeph ">createSheet()</codeph>.</li><li class="- topic/li ">If the Object argument passed is not null, create a new Sprite instance named
 * <codeph class="+ topic/ph pr-d/codeph ">img</codeph> that is used to draw a white rectangle using the coordinate and dimension properties
 * of the Object passed.  The white rectangle is added to the display list of the Sprite object using
 * <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">txt</codeph> TextField is added to the display list of the Sprite object using
 * <codeph class="+ topic/ph pr-d/codeph ">addChild()</codeph>.</li></ol></li><li class="- topic/li ">Back in the constructor, the print method that is enabled (not commented out) is called.  Since the
 * methods are very similar, <codeph class="+ topic/ph pr-d/codeph ">printOnePerPage()</codeph> is described below.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">printOnePerPage()</codeph> does the following:
 * <ol outputclass="A" class="- topic/ol "><li class="- topic/li ">Declare a new PrintJob object named <codeph class="+ topic/ph pr-d/codeph ">pj</codeph> and <codeph class="+ topic/ph pr-d/codeph ">pagesToPrint</codeph> as a uint.</li><li class="- topic/li ">Open the operating system's native print dialog box and wait for user to click <codeph class="+ topic/ph pr-d/codeph ">OK</codeph>.</li><li class="- topic/li ">Check the orientation and if Landscape is selected, throw an error and exit.</li><li class="- topic/li ">Set up the page height and width for <codeph class="+ topic/ph pr-d/codeph ">sheet1</codeph> and <codeph class="+ topic/ph pr-d/codeph ">sheet2</codeph>.</li><li class="- topic/li ">Send <codeph class="+ topic/ph pr-d/codeph ">sheet1</codeph> and <codeph class="+ topic/ph pr-d/codeph ">sheet2</codeph> to the print spooler using <codeph class="+ topic/ph pr-d/codeph ">addPage()</codeph>.</li><li class="- topic/li ">If the number of pages to print is &gt; 0, print all spooled pages.</li></ol></li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">draw()</codeph> method is called, which re-sizes the two Sprite properties to fit on the stage
 * and re-positions <codeph class="+ topic/ph pr-d/codeph ">sheet2</codeph> such that it is just right of <codeph class="+ topic/ph pr-d/codeph ">sheet1</codeph>.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note: </b> the constructor is set up such that one of three printing methods (one sheet per
 * page, two sheets per page, or printing on the top half of the page) can be selected, based on preference.
 * This example will not work correctly unless exactly two of the print methods are disabled using code
 * comments.  The example is set up such that <codeph class="+ topic/ph pr-d/codeph ">printOnePerPage()</codeph> will be called.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.printing.PrintJob;
 * import flash.printing.PrintJobOrientation;
 * import flash.display.Stage;
 * import flash.display.Sprite;
 * import flash.text.TextField;
 * import flash.geom.Rectangle;
 *
 *   public class PrintJobExample extends Sprite {
 * private var sheet1:Sprite;
 * private var sheet2:Sprite;
 *
 *   public function PrintJobExample() {
 * init();
 * printOnePerPage();
 * //            printTwoPerPage();
 * //            printTopHalf();
 * draw();
 * }
 *
 *   private function init():void {
 * sheet1 = new Sprite();
 * createSheet(sheet1, "Once upon a time...", {x:10, y:50, width:80, height:130});
 *
 *   sheet2 = new Sprite();
 * createSheet(sheet2, "There was a great story to tell, and it ended quickly.\n\nThe end.", null);
 * }
 *
 *   private function createSheet(sheet:Sprite, str:String, imgValue:Object):void {
 * sheet.graphics.beginFill(0xEEEEEE);
 * sheet.graphics.lineStyle(1, 0x000000);
 * sheet.graphics.drawRect(0, 0, 100, 200);
 * sheet.graphics.endFill();
 *
 *   var txt:TextField = new TextField();
 * txt.height = 200;
 * txt.width = 100;
 * txt.wordWrap = true;
 * txt.text = str;
 *
 *   if(imgValue != null) {
 * var img:Sprite = new Sprite();
 * img.graphics.beginFill(0xFFFFFF);
 * img.graphics.drawRect(imgValue.x, imgValue.y, imgValue.width, imgValue.height);
 * img.graphics.endFill();
 * sheet.addChild(img);
 * }
 * sheet.addChild(txt);
 * }
 *
 *   private function printOnePerPage():void {
 * var pj:PrintJob = new PrintJob();
 * var pagesToPrint:uint = 0;
 * if(pj.start()) {
 * if(pj.orientation == PrintJobOrientation.LANDSCAPE) {
 * throw new Error("Without embedding fonts you must print one sheet per page with an orientation of portrait.");
 * }
 *
 *   sheet1.height = pj.pageHeight;
 * sheet1.width = pj.pageWidth;
 * sheet2.height = pj.pageHeight;
 * sheet2.width = pj.pageWidth;
 *
 *   try {
 * pj.addPage(sheet1);
 * pagesToPrint++;
 * }
 * catch(e:Error) {
 * // do nothing
 * }
 *
 *   try {
 * pj.addPage(sheet2);
 * pagesToPrint++;
 * }
 * catch(e:Error) {
 * // do nothing
 * }
 *
 *   if(pagesToPrint &gt; 0) {
 * pj.send();
 * }
 * }
 * }
 *
 *   private function printTwoPerPage():void {
 * var pj:PrintJob = new PrintJob();
 * var pagesToPrint:uint = 0;
 * if(pj.start()) {
 * if(pj.orientation == PrintJobOrientation.PORTRAIT) {
 * throw new Error("Without embedding fonts you must print two sheets per page with an orientation of landscape.");
 * }
 *
 *   sheet1.height = pj.pageHeight;
 * sheet1.width = pj.pageWidth/2;
 * sheet2.height = pj.pageHeight;
 * sheet2.width = pj.pageWidth/2;
 *
 *   var sheets:Sprite = new Sprite();
 * sheets.addChild(sheet1);
 * sheets.addChild(sheet2);
 * sheets.getChildAt(1).x = sheets.getChildAt(0).width;
 * try {
 * pj.addPage(sheets);
 * pagesToPrint++;
 * }
 * catch(e:Error) {
 * // do nothing
 * }
 *
 *   if(pagesToPrint &gt; 0) {
 * pj.send();
 * }
 * }
 * }
 *
 *   private function printTopHalf():void {
 * var pj:PrintJob = new PrintJob();
 * var pagesToPrint:uint = 0;
 * if(pj.start()) {
 * if(pj.orientation == PrintJobOrientation.PORTRAIT) {
 * throw new Error("Without embedding fonts you must print the top half with an orientation of landscape.");
 * }
 *
 *   sheet1.height = pj.pageHeight;
 * sheet1.width = pj.pageWidth/2;
 * sheet2.height = pj.pageHeight;
 * sheet2.width = pj.pageWidth/2;
 *
 *   var sheets:Sprite = new Sprite();
 * sheets.addChild(sheet1);
 * sheets.addChild(sheet2);
 * sheets.getChildAt(1).x = sheets.getChildAt(0).width;
 * try {
 * pj.addPage(sheets, new Rectangle(0, 0, sheets.width, sheets.height/2));
 * pagesToPrint++;
 * }
 * catch(e:Error) {
 * // do nothing
 * }
 *
 *   if(pagesToPrint &gt; 0) {
 * pj.send();
 * }
 * }
 * }
 *
 *   private function draw():void {
 * var sheetWidth:Number = this.stage.stageWidth/2;
 * var sheetHeight:Number = this.stage.stageHeight;
 *
 *   addChild(sheet1);
 * sheet1.width = sheetWidth;
 * sheet1.height = sheetHeight;
 *
 *   addChild(sheet2);
 * sheet2.width = sheetWidth;
 * sheet2.height = sheetHeight;
 * sheet2.x = sheet1.width;
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example demonstrates additional printing features.
 * The example initializes the PrintJob settings for number of copies,
 * paper size (legal), and page orientation (landscape). It forces the
 * Page Setup dialog to be displayed first, then starts the print job
 * by displaying the Print dialog.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 * import flash.display.Stage;
 * import flash.geom.Rectangle;
 * import flash.printing.PaperSize;
 * import flash.printing.PrintJob;
 * import flash.printing.PrintJobOrientation;
 * import flash.printing.PrintUIOptions;
 * import flash.text.TextField;
 *
 *   public class PrintJobExample extends Sprite
 * {
 * private var bg:Sprite;
 * private var txt:TextField;
 * private var pj:PrintJob;
 * private var uiOpt:PrintUIOptions;
 *
 *   public function PrintJobExample():void
 * {
 * var pj = new PrintJob();
 * uiOpt = new PrintUIOptions();
 * initPrintJob();
 * initContent();
 * draw();
 * printPage();
 * }
 *
 *   private function printPage():void
 * {
 * if (pj.supportsPageSetupDialog)
 * {
 * pj.showPageSetupDialog();
 * }
 *
 *   if (pj.start2(uiOpt, true))
 * {
 * try
 * {
 * pj.addPage(this, new Rectangle(0, 0, 100, 100));
 * }
 * catch (error:Error)
 * {
 * // Do nothing.
 * }
 * pj.send();
 * }
 * else
 * {
 * txt.text = "Print job terminated";
 * pj.terminate();
 * }
 * }
 *
 *   private function initContent():void
 * {
 * bg = new Sprite();
 * bg.graphics.beginFill(0x00FF00);
 * bg.graphics.drawRect(0, 0, 100, 200);
 * bg.graphics.endFill();
 *
 *   txt = new TextField();
 * txt.border = true;
 * txt.text = "Hello World";
 * }
 *
 *   private function initPrintJob():void
 * {
 * pj.setPaperSize(PaperSize.LEGAL);
 * pj.orientation = PrintJobOrientation.LANDSCAPE;
 * pj.copies = 2;
 * pj.jobName = "Flash test print";
 * }
 *
 *   private function draw():void
 * {
 * addChild(bg);
 * addChild(txt);
 * txt.x = 50;
 * txt.y = 50;
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 */

using namespace flash::display;
using namespace flash::events;
using namespace flash::geom;
using namespace flash::printing;

namespace flash
{
    namespace printing
    {
        class PrintJob : public flash::events::EventDispatcher
        {
            /**
             * Indicates whether the PrintJob class is supported on the current platform (true)
             * or not (false).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static bool      isSupported();

            /**
             * The overall paper height, in points. This property is available only
             * after a call to the PrintJob.start() method has been made.
             *
             *   Note: For AIR 2 or later, this property is deprecated. Use
             * paperArea instead, which measures the
             * paper dimensions in fractional points.
             * @langversion 3.0
             * @playerversion   Flash 9.
             */
        public:
            int          paperHeight();

            /**
             * The overall paper width, in points. This property is available only
             * after a call to the PrintJob.start() method has been made.
             *
             *   Note: For AIR 2 or later, this property is deprecated. Use
             * paperArea instead, which measures the
             * paper dimensions in fractional points.
             * @langversion 3.0
             * @playerversion   Flash 9.
             */
        public:
            int          paperWidth();

            /**
             * The height of the largest area which can be centered in the actual printable
             * area on the page, in points.
             * Any user-set margins are ignored. This property is available only
             * after a call to the PrintJob.start() method has been made.
             *
             *   Note: For AIR 2 or later, this property is deprecated. Use
             * printableArea instead, which measures
             * the printable area in fractional points and describes off-center printable areas
             * accurately.
             * @langversion 3.0
             * @playerversion   Flash 9.
             */
        public:
            int          pageHeight();

            /**
             * The width of the largest area which can be centered in the actual printable
             * area on the page, in points.
             * Any user-set margins are ignored. This property is available only
             * after a call to the PrintJob.start() method has been made.
             *
             *   Note: For AIR 2 or later, this property is deprecated. Use
             * printableArea instead, which measures
             * the printable area in fractional points and describes off-center printable areas
             * accurately.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   AIR 1.0
             */
        public:
            int          pageWidth();

            /**
             * The image orientation for printing. The acceptable values are defined as constants
             * in the PrintJobOrientation class.
             *
             *   Note: For AIR 2 or later, set this property before
             * starting a print job to set the default orientation in the Page Setup and Print dialogs.
             * Set the property while a print job is in progress (after calling start() or
             * start2() to set the orientation for a range of pages within the job.
             * @langversion 3.0
             * @playerversion   Flash 9  read only
             * @playerversion   AIR 1.0  read only
             * @playerversion   AIR 2  read-write
             */
        public:
            std::string       orientation();

            /**
             * Creates a PrintJob object that you can use to print one or more pages.
             * After you create a PrintJob object, you need to use (in the following sequence) the
             * PrintJob.start(), PrintJob.addPage(), and then
             * PrintJob.send() methods to send the print job to the printer.
             *
             *   For example, you can replace the [params] placeholder text for the
             * myPrintJob.addPage() method calls with custom parameters as shown in the
             * following code:
             * // create PrintJob object
             * var myPrintJob:PrintJob = new PrintJob();
             *
             *   // display Print dialog box, but only initiate the print job
             * // if start returns successfully.
             * if (myPrintJob.start()) {
             *
             *   // add specified page to print job
             * // repeat once for each page to be printed
             * try {
             * myPrintJob.addPage([params]);
             * }
             * catch(e:Error) {
             * // handle error
             * }
             * try {
             * myPrintJob.addPage([params]);
             * }
             * catch(e:Error) {
             * // handle error
             * }
             *
             *   // send pages from the spooler to the printer, but only if one or more
             * // calls to addPage() was successful. You should always check for successful
             * // calls to start() and addPage() before calling send().
             * myPrintJob.send();
             * }
             * In AIR 2 or later, you can create and use multiple PrintJob instances. Properties set on
             * the PrintJob instance are retained after printing completes. This allows you to re-use a PrintJob
             * instance and maintain a user's selected printing preferences, while offering different printing
             * preferences for other content in your application. For content in Flash Player and in AIR prior to version 2, you cannot create a
             * second PrintJob object while the first one is still active.
             * If you create a second PrintJob object (by calling new  PrintJob())
             * while the first PrintJob object is still active, the second PrintJob object
             * will not be created. So, you may check for the myPrintJob value before
             * creating a second PrintJob.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @maelexample See <code>PrintJob.addPage()</code>.
             * @throws  IllegalOperationError  In Flash Player and AIR prior to AIR 2, throws an exception if another PrintJob object is still active.
             */
        public:
            PrintJob();

            /**
             * Displays the operating system's Print dialog box and starts spooling. The Print dialog box lets the user change print settings. When the
             * PrintJob.start() method returns successfully (the user clicks OK in the Print dialog
             * box), the following properties are populated, representing the user's chosen print settings:
             *
             *   PropertyTypeUnitsNotesPrintJob.paperHeightNumberPointsOverall paper height.PrintJob.paperWidthNumberPointsOverall paper width.PrintJob.pageHeightNumberPointsHeight of actual printable area on the page; any user-set margins are ignored.PrintJob.pageWidthNumberPointsWidth of actual printable area on the page; any user-set margins are ignored.PrintJob.orientationString"portrait" (flash.printing.PrintJobOrientation.PORTRAIT) or "landscape" (flash.printing.PrintJobOrientation.LANDSCAPE).Note: If the user cancels the Print dialog box, the properties are not populated.After the user clicks OK in the Print dialog box, the player begins spooling a print job to the operating system.
             * Because the operating system then begins displaying information to the user about the printing progress,
             * you should call the PrintJob.addPage() and PrintJob.send() calls as soon as possible to send
             * pages to the spooler. You can use the read-only height, width, and orientation properties this method populates to
             * format the printout.Test to see if this method returns true (when the user clicks OK in the operating system's Print
             * dialog box) before any subsequent calls to PrintJob.addPage() and PrintJob.send():
             * <codeblock>
             *
             *   var myPrintJob:PrintJob = new PrintJob();
             * if(myPrintJob.start()) {
             * // addPage() and send() statements here
             * }
             *
             *   </codeblock>
             * For the given print job instance, if any of the following intervals last more than
             * 15 seconds the next call to PrintJob.start() will return false:PrintJob.start() and the first PrintJob.addPage()One PrintJob.addPage() and the next PrintJob.addPage()The last PrintJob.addPage() and PrintJob.send()
             * @return  A value of true if the user clicks OK when the Print dialog box appears; false if the user clicks Cancel or if an error occurs.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @playerversion   Flash 9.
             * @throws  IllegalOperationError in AIR 2 or later, if another PrintJob is currently active
             */
        public:
            bool  start();

            /**
             * Sends spooled pages to the printer after successful calls to the start() or
             * start2() and addPage() methods.
             *
             *   This method does not succeed if the call to the start() or start2() method fails, or
             * if a call to the addPage() method throws an exception. To avoid an error,
             * check that the start() or start2() method returns
             * true and catch any addPage() exceptions before calling
             * this method. The following example demonstrates how to properly check for errors
             * before calling this method:
             * <codeblock>
             *
             *   var myPrintJob:PrintJob = new PrintJob();
             * if (myPrintJob.start()) {
             * try {
             * myPrintJob.addPage([params]);
             * }
             * catch(e:Error) {
             * // handle error
             * }
             *
             *   myPrintJob.send();
             * }
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 9.
             */
        public:
            void     send();

            /**
             * Sends the specified Sprite object as a single page to the print spooler. Before using this
             * method, you must create a PrintJob object and then use start() or
             * start2(). Then,
             * after calling addPage() one or more times for a print job, use
             * send() to send the spooled pages to the printer. In other words, after you create
             * a PrintJob object, use (in the following sequence) start() or
             * start2(), addPage(), and then send() to send
             * the print job to the printer. You can call addPage() multiple times after a
             * single call to start() to print several pages in a print job.
             *
             *   If addPage() causes Flash Player to throw an exception (for example,
             * if you haven't called start() or the user cancels the print job), any
             * subsequent calls to addPage() fail. However, if previous calls to
             * addPage() are successful, the concluding send() command sends
             * the successfully spooled pages to the printer.If the print job takes more than 15 seconds to complete an addPage()
             * operation, Flash Player throws an exception on the next addPage() call.If you pass a value for the printArea parameter, the
             * x and y coordinates of the
             * printArea Rectangle map to the upper-left corner (0, 0 coordinates) of the
             * printable area on the page. The read-only properties
             * pageHeight and pageWidth describe the printable area set by
             * start(). Because the printout aligns with the upper-left corner
             * of the printable area on the page, when the area defined in printArea
             * is bigger than the printable area on the page, the printout is cropped to the right
             * or bottom (or both) of the area defined by printArea.
             * In Flash Professional, if you don't pass a value for printArea and the
             * Stage is larger than the printable area, the same type of clipping
             * occurs. In Flex or Flash Builder, if you don't pass a value for
             * printArea and the screen is larger than the printable area, the
             * same type of clipping takes place.If you want to scale a Sprite object before you print it, set scale
             * properties (see flash.display.DisplayObject.scaleX and
             * flash.display.DisplayObject.scaleY) before calling this method,
             * and set them back to their original values after printing. The scale of a Sprite
             * object has no relation to printArea. That is, if you specify a print
             * area that is 50 x 50 pixels, 2500 pixels are printed. If you scale the Sprite object,
             * the same 2500 pixels are printed, but the Sprite object is printed at the scaled size.The Flash Player printing feature supports PostScript and non-PostScript printers.
             * Non-PostScript printers convert vectors to bitmaps.
             * @param   sprite  The Sprite containing the content to print.
             * @param   printArea   A Rectangle object that specifies the area to print.
             *
             *     A rectangle's width and height are pixel values. A printer uses points as print units
             *   of measurement. Points are a fixed physical size (1/72 inch), but the size of a pixel,
             *   onscreen, depends on the resolution of the particular screen. So, the conversion rate
             *   between pixels and points depends on the printer settings and whether the sprite is
             *   scaled. An unscaled sprite that is 72 pixels wide prints out one inch wide, with
             *   one point equal to one pixel, independent of screen resolution.You can use the following equivalencies to convert inches
             *   or centimeters to twips or points (a twip is 1/20 of a point):1 point = 1/72 inch = 20 twips1 inch = 72 points = 1440 twips1 cm = 567 twipsIf you omit the printArea parameter, or if it is passed incorrectly,
             *   the full area of the sprite parameter is printed.If you don't want to specify a value for printArea but want to specify a value for options
             *   or frameNum, pass null for printArea.
             * @param   options An optional parameter that specifies whether to print as vector or bitmap.
             *   The default value is null, which represents a request for vector printing.
             *   To print sprite as a
             *   bitmap, set the printAsBitmap property of the PrintJobOptions object
             *   to true. Remember the following suggestions when determining whether to
             *   set printAsBitmap to true:
             *
             *     If the content you're printing includes a bitmap image, set
             *   printAsBitmap to true to include any alpha transparency
             *   and color effects.If the content does not include bitmap images, omit this parameter
             *   to print the content in higher quality vector format.If options is omitted or is passed incorrectly, vector printing is used.
             *   If you don't want to specify a value for
             *   options but want to specify a value for frameNumber,
             *   pass null for options.
             * @param   frameNum    An optional number that lets you specify which frame
             *   of a MovieClip object to print. Passing a frameNum does not invoke
             *   ActionScript on that frame. If you omit this parameter and the
             *   sprite parameter is a MovieClip object, the current
             *   frame in sprite is printed.
             * @langversion 3.0
             * @playerversion   Flash 9.
             * @throws  Error Throws an exception if you haven't called start() or the
             *   user cancels the print job
             */
        public:
            void     addPage(Sprite *sprite, Rectangle *printArea=NULL, PrintJobOptions *options=NULL, int frameNum=0);
        };
    }
}

#endif // FLEX11_6_FLASH_PRINTING_PRINTJOB_AS
#endif // __cplusplus


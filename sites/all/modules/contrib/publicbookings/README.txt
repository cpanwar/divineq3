Public Bookings
Author: Carson Lam

Description
--

Prerequisites
- Bookings API

ALPHA RELEASE NOTES
===================
Many things still aren't done, including:
- Using Calendar module to display bookings and availabilities
  - exposing data to Views to allow Calendar use (?)
- Sending out confirmation and update emails
- Picking resources to be booked together with your 'primary' booking
- Approving/rejecting booking requests
- Deletions

At this point, Public Bookings cannot do anything useful for you. Sorry!

Coming later:
- Icons
- AJAX+JSON for conflict checking
- reCAPTCHA
- Granularity for times
- More settings
- Theming

A booking that starts at exactly the same time as when another ends is
considered to be conflicting. This is technically normal. Later, this
will be worked around by removing 1 second from the end time upon saving,
and adding back that 1 second upon display.

Be sure to install all the Date API patches mentioned in the Bookings API
README.txt.

Before you can book a resource, you first have to add at least one at
admin/content/publicbookings/resource.


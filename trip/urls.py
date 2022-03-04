urls.py
from django.contrib.auth.views import logout

urlpatterns = [
  url(r'^logout/$', logout, {'template_name': 'index.html'}, name='logout'), 
]
from django.urls import path, include
from api.core.v1 import api_route_v1


urlpatterns = [
    path("v1/", include(api_route_v1.urls))
]
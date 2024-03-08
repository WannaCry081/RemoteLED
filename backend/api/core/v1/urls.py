from rest_framework import routers
from api.core.v1.viewsets import LightViewSet


router = routers.DefaultRouter()
router.register(r"light", LightViewSet, basename="light")